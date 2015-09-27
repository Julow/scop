/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/27 17:38:54 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "scop.h"
#include "shader_loader.h"
#include "mesh_loader.h"
#include "resources.h"
#include "obj.h"
#include "math_utils.h"
#include "events.h"
#include "utils.h"
#include <stdlib.h>
#include <math.h>

/*
** ========================================================================== **
** Animation
** TODO: smooth
*/

#define F_ANIM_END			(1 << 1)
#define F_ANIM_REPEAT		(1 << 2)
#define F_ANIM_REPEAT_REV	(1 << 3)

#define F_ANIM_ONREPEAT_REV	(1 << 4)

struct			s_anim
{
	t_ulong			start_time;
	float			duration;
	int				flags;
	void			(*callback)(void *env, t_obj *obj, float delta);
};

void			anim_update(void *env, t_obj *obj, t_anim *anim, t_ulong now)
{
	float			delta;

	if (anim->flags & F_ANIM_END)
		return ;
	delta = (float)(now - anim->start_time) / anim->duration / 1000.f;
	if (delta >= 1.f)
	{
		if (anim->flags & (F_ANIM_REPEAT | F_ANIM_REPEAT_REV))
		{
			delta -= 1.f;
			if (anim->flags & F_ANIM_ONREPEAT_REV)
				anim->flags &= ~F_ANIM_ONREPEAT_REV;
			else if (anim->flags & F_ANIM_REPEAT_REV)
				anim->flags |= F_ANIM_ONREPEAT_REV;
		}
		else
		{
			anim->flags |= F_ANIM_END;
			delta = 1.f;
		}
		anim->start_time = now;
	}
	if (anim->flags & F_ANIM_ONREPEAT_REV)
		delta = 1.f - delta;
	ft_printf("\rdelta: %f", delta);
	anim->callback(env, obj, delta);
}

void			anim_start(t_anim *anim)
{
	anim->start_time = ft_clock(0);
}

/*
** Create an anim
** -
** d		duration (in ms)
** f		flags
** c		callback
*/
#define ANIM(d,f,c)	(&(t_anim){0, d, f, c})

struct			s_anim_move
{
	t_anim			anim;
	t_vec3			from;
	t_vec3			to;
};

void			anim_f_move(void *env, t_obj *obj, float delta)
{
	struct s_anim_move *const	anim = (struct s_anim_move*)obj->anim;
	t_vec3						pos;

	pos.x = (anim->to.x - anim->from.x) * delta;
	pos.y = (anim->to.y - anim->from.y) * delta;
	pos.z = (anim->to.z - anim->from.z) * delta;
	ft_transform_move(&(obj->transform), pos);
	(void)env;
}

/*
** Create a move anim
** -
** d		duration
** l		flags
** f		from (x, y, z)
** t		to (x, y, z)
*/
#define ANIM_MOVE(d,l,f,t)	(t_anim*)(&(struct s_anim_move){{0,d,l,&anim_f_move},VEC3 f,VEC3 t})

/*
** ========================================================================== **
** Scene
*/
typedef struct	s_scene_obj
{
	t_sub			mesh;
	t_renderer		renderer;
	t_anim			*anim;
	t_vec3			pos;
	t_vec3			rot;
	t_vec3			shear;
	float			scale;
	int				reflect;
}				t_scene_obj;

#define S_OBJ(m,e,a,p,r,h,k,f)	((t_scene_obj){SUBC(m),e,a,VEC3 p,VEC3 r,VEC3 h,k,f})

static const t_scene_obj	g_scene[] = {
	S_OBJ("42.obj", &simple_renderer, NULL, (-20.f, 0.f, 5.f), (1.f, 0.2f, 0.f), (0.f, 0.f, 0.f), 1.f, 0),
	S_OBJ("cube.obj", &simple_renderer, NULL, (20.f, 0.f, 20.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), 1.f, 0),
	S_OBJ("cube.obj", &simple_renderer, NULL, (-700.f, 120.f, -750.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), 1.f, 0),
	S_OBJ("teapot.obj", &simple_renderer, ANIM_MOVE(2000, F_ANIM_REPEAT, (20.f, 0.f, -30.f), (20.f, -7.f, 30.f)), (-35.f, -7.f, 0.f), (0.f, M_PI / 2.f, 0.f), (0.f, 0.f, 0.f), 1.f, REFLECT_Y),
	S_OBJ("teapot2.obj", &simple_renderer, NULL, (-40.f, -5.f, -5.f), (0.f, 2.f, 0.f), (0.f, 0.f, 0.f), 0.1f, 0),
	S_OBJ("cube.obj", &simple_renderer, NULL, (300.f, -10.f, -50.f), (0.f, 0.f, 0.f), (0.f, 0.5f, 0.5f), 50.f, 0),
	S_OBJ("venice.obj", &simple_renderer, NULL, (0.f, -40.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), 1.f, 0),
};

t_bool			load_scene(t_scop *scop)
{
	t_obj			obj;
	int				i;

	i = -1;
	while (++i < G_ARRAY_LEN(g_scene))
	{
		ft_bzero(&obj, sizeof(t_obj));
		if ((obj.mesh = get_res(g_res_t.mesh, g_scene[i].mesh)) == NULL)
			continue ;
		obj.renderer = g_scene[i].renderer;
		obj.anim = g_scene[i].anim;
		if (obj.anim != NULL)
			anim_start(obj.anim);
		ft_transform_move(&(obj.transform), g_scene[i].pos);
		ft_transform_rotate(&(obj.transform), g_scene[i].rot);
		ft_transform_scale(&(obj.transform), g_scene[i].scale);
		ft_transform_reflect(&(obj.transform), g_scene[i].reflect);
		ft_transform_shear(&(obj.transform), g_scene[i].shear);
		ft_vpush_back(&(scop->objects), &obj, 1);
	}
	return (true);
}

/*
** ========================================================================== **
** Shader def
*/

// static void		depth_glsl_pre(t_shader const *shader, t_scop *scop, t_obj *obj)
// {
// 	glUniformMatrix4fv(shader->loc[0], 1, GL_TRUE, (float*)ft_transform_get(&(obj->transform)));
// 	glUniformMatrix4fv(shader->loc[1], 1, GL_TRUE, (float*)camera_get_view(&(scop->camera)));
// 	glUniformMatrix4fv(shader->loc[2], 1, GL_TRUE, (float*)&(scop->projection_m));
// 	glUniform3fv(shader->loc[3], 1, (float*)&(scop->camera.position));
// }

// void			depth_renderer(t_scop *scop, t_obj *obj)
// {
// 	int			i;
// 	int			offset;

// 	glUseProgram(obj->shader->handle);
// 	depth_glsl_pre(obj->shader, scop, obj);
// 	glBindVertexArray(obj->mesh->vao);
// 	offset = 0;
// 	i = -1;
// 	while (++i < obj->mesh->mtl_count)
// 		offset += obj->mesh->mtl[i].count;
// 	glDrawArrays(GL_TRIANGLES, 0, offset);
// }

/*
** ========================================================================== **
** Anim obj
*/

static void		anim_obj(t_scop *scop, t_obj *obj, t_ulong now)
{
	if (obj->anim != NULL)
		anim_update(scop, obj, obj->anim, now);
}

void			anim(t_scop *scop)
{
	const t_ulong	now = ft_clock(0);
	int				i;

	i = -1;
	while (++i < scop->objects.length)
		anim_obj(scop, VECTOR_GET(scop->objects, i), now);
}

/*
** ========================================================================== **
** Render obj
*/

static void		render_obj(t_scop *scop, t_obj *obj)
{
	obj->renderer(scop, obj);
}

void			render(t_scop *scop)
{
	int				i;

	glClearColor(0.f, 0.6f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	i = -1;
	while (++i < scop->objects.length)
		render_obj(scop, VECTOR_GET(scop->objects, i));
}

/*
** ========================================================================== **
** Main
*/

static void		handle_input(t_scop *scop, float elapsed)
{
	t_vec3			pos;
	t_vec2			look;

	if (handle_key_hold(scop, elapsed, &pos))
		camera_move(&(scop->camera), pos);
	if (handle_cursor_move(scop, &look))
		camera_look(&(scop->camera), look);
}

int				main(void)
{
	t_scop			scop;
	t_fps			fps;
	int				last_flags;

	ft_bzero(&scop, sizeof(scop));
	scop.objects = VECTOR(t_obj);
	scop.camera = CAMERA(VEC3_0(), VEC2_0());
	scop.projection_m = ft_mat4perspective(PERSPECTIVE_FOV, WIN_RATIO,
		PERSPECTIVE_NEAR, PERSPECTIVE_FAR);
	if (!init_window(&scop) || !load_scene(&scop))
		return (1);
	init_events(scop.window, &scop);
	fps = fps_init(200000);
	last_flags = -1;
	while (!glfwWindowShouldClose(scop.window))
	{
		fps_start(&fps);
		render(&scop);
		glfwSwapBuffers(scop.window);
		glfwPollEvents();
		if (fps_end(&fps) || scop.flags != last_flags)
		{
			last_flags = scop.flags;
			ft_printf("\r%30 FPS: %-2lld t: %-3lld flags: %016b "
				"pos: [ %f, %f, %f ] look: [ %f, %f ]%5 ",
				fps.average_fps, fps.average_time, scop.flags,
				scop.camera.position.x, scop.camera.position.y,
				scop.camera.position.z, scop.camera.look.x, scop.camera.look.y);
		}
		handle_input(&scop, fps.elapsed);
		anim(&scop);
	}
	ft_printf("\n");
	glfwTerminate();
	return (0);
}
