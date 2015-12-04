/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/04 19:13:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "shader.h"
#include "mesh.h"
#include "mesh_loader.h"
#include "obj.h"
#include "anim.h"
#include "obj_anim.h"
#include "render.h"
#include "transform.h"
#include "math_utils.h"
#include "ft/ft_printf.h"
#include "events.h"
#include "utils.h"
#include <stdlib.h>
#include <math.h>

/*
** ========================================================================== **
** Scene
*/
typedef struct s_scene_obj		t_scene_obj;

struct	s_scene_obj
{
	t_sub			mesh;
	t_anim			*anim;
	t_transform		transform;
	t_scene_obj		*childs;
	int				child_count;
};

#define TRANSFORM(p,o,r,h,s,f)	((t_transform){{},VEC3 p,VEC3 o,VEC3 r,VEC3 h, VEC3 s,f})
#define TRANSFORM0()			((0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0)
#define S_OBJ(m,a,t,c)			((t_scene_obj){SUBC(m),a,TRANSFORM t,(t_scene_obj*)c,(c == NULL) ? 0 : G_ARRAY_LEN(c)})

static const t_scene_obj	g_scene[] = {
	S_OBJ(NULL, ANIM_MOVE(1800, F_ANIM_REVERSE, (0.f, 0.f, 0.f), (10.f, 0.f, 10.f), &smooth_linear), TRANSFORM0(), ((t_scene_obj[]){
		S_OBJ("res/obj/cube.obj", NULL, ((0.f, -15.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (100.f, 10.f, 100.f), 0), NULL),
		S_OBJ("res/obj/cube.obj", ANIM_SCALE3(1000, F_ANIM_REVERSE, (1.5f, 0.5f, 1.0f), (1.f, 1.f, 1.f), &smooth_elastic),
			((0.f, -5.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0), NULL),
	})),
	S_OBJ("res/obj/42.obj", ANIM_SCALE3(1000, F_ANIM_REVERSE, (1.5f, 0.5f, 1.0f), (1.f, 1.f, 1.f), &smooth_elastic), ((-20.f, 0.f, 5.f), (0.f, 0.f, 0.f), (1.f, 0.2f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0), NULL),
	// S_OBJ("res/obj/42.obj", ANIM_SCALE(1200, F_ANIM_REPEAT, (0.8f, 0.8f, 0.8f), (2.f, 2.f, 2.f), &smooth_elastic), ((-20.f, 0.f, 5.f), (0.f, 0.f, 0.f), (1.f, 0.2f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0)),
	// S_OBJ("res/obj/cube.obj", NULL, ((20.f, 0.f, 20.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0)),
	// S_OBJ("res/obj/cube.obj", NULL, ((-700.f, 120.f, -750.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0)),
	S_OBJ("res/obj/teapot.obj", ANIM_ROT(2000, F_ANIM_RESTART, (0.f, 0.f, 0.f), (M_PI * 2.f, M_PI * 2.f, M_PI * 2.f), &smooth_linear), ((-35.f, 10.f, 0.f), (5.f, 5.f, 5.f), (0.f, M_PI / 2.f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0), NULL),
	// S_OBJ("res/obj/teapot2.obj", ANIM_MOVE(1800, F_ANIM_RESTART, (10.f, -10.f, 0.f), (10.f, 10.f, 0.f), &smooth_bounce), ((-40.f, -5.f, -5.f), (0.f, 0.f, 0.f), (0.f, 2.f, 0.f), (0.f, 0.f, 0.f), (0.5f, 0.5f, 0.5f), 0)),
	// S_OBJ("res/obj/teapot2.obj", ANIM_MOVE(1800, F_ANIM_REPEAT, (20.f, -10.f, 0.f), (20.f, 10.f, 0.f), &smooth_bounce), ((-40.f, -5.f, -5.f), (0.f, 0.f, 0.f), (0.f, 2.f, 0.f), (0.f, 0.f, 0.f), (0.5f, 0.5f, 0.5f), 0)),
	// S_OBJ("res/obj/teapot2.obj", ANIM_MOVE(1800, F_ANIM_REVERSE, (0.f, -10.f, 0.f), (0.f, 10.f, 0.f), &smooth_bounce), ((-40.f, -5.f, -5.f), (0.f, 0.f, 0.f), (0.f, 2.f, 0.f), (0.f, 0.f, 0.f), (0.5f, 0.5f, 0.5f), 0)),
	// S_OBJ("res/obj/cube.obj", ANIM_SHEAR(4000, F_ANIM_REPEAT, (0.5f, 0.f, 0.f), (-0.5f, 0.5f, -0.5f), &smooth_in_out), ((300.f, -10.f, -50.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.5f, 0.5f), (50.f, 50.f, 50.f), 0)),
	// S_OBJ("res/obj/venice.obj", NULL, ((0.f, -40.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0)),
};

static t_obj	*load_obj(t_scene_obj const *data)
{
	t_obj			*obj;
	t_mesh const	*mesh;
	t_obj			*tmp;
	int				i;

	if (data->mesh.str == NULL)
		mesh = NULL;
	else
		mesh = load_mesh(data->mesh);
	obj = MAL1(t_obj);
	obj->anim = data->anim;
	obj->mesh = mesh;
	if (obj->anim != NULL)
		anim_start(obj->anim); // TODO: move to scene
	obj->transform = data->transform;
	obj->childs = VECTOR(t_obj*);
	i = -1;
	while (++i < data->child_count)
		if ((tmp = load_obj(data->childs + i)) != NULL)
			ft_vpush_back(&(obj->childs), &tmp, 1);
	return (obj);
}

t_bool			load_scene(t_scop *scop)
{
	t_obj			*obj;
	int				i;

	i = -1;
	while (++i < G_ARRAY_LEN(g_scene))
		if ((obj = load_obj(g_scene + i)) != NULL)
			ft_vpush_back(&(scop->objects), &obj, 1);
	return (true);
}

/*
** ========================================================================== **
** Anim obj
*/

static void		anim_objs(t_vector *objs, t_ulong now)
{
	t_obj			*obj;
	int				i;

	i = -1;
	while (++i < objs->length)
	{
		obj = *(t_obj**)VECTOR_GET(*objs, i);
		if (obj->anim != NULL)
			anim_update(obj, obj->anim, now);
		if (obj->childs.length > 0)
			anim_objs(&(obj->childs), now);
	}
}

void			anim(t_scop *scop)
{
	anim_objs(&(scop->objects), ft_clock(0));
}

/*
** ========================================================================== **
** Render obj
** TODO: module scene
*/

void			render_objs(t_vector *objs, t_render_params *params,
					t_mat4 const *const parent_mat)
{
	t_mat4				top_matrix;
	t_obj				*obj;
	int					i;

	i = -1;
	while (++i < objs->length)
	{
		obj = *(t_obj**)VECTOR_GET(*objs, i);
		if (parent_mat == NULL)
			params->top_matrix = ft_transform_get(&(obj->transform));
		else
			params->top_matrix = ft_mat4mult(ft_transform_get(&(obj->transform)),
				parent_mat, &top_matrix);
		if (obj->mesh != NULL)
			simple_render(params, obj->mesh);
		if (obj->childs.length > 0)
			render_objs(&(obj->childs), params, params->top_matrix);
	}
}

void			render(t_scop *scop)
{
	t_render_params		params;

	// ft_mat4mult(&scop->projection_m, camera_get_view(&(scop->camera)), &top_matrix);
	// ft_mat4transpose(&top_matrix);
	params = (t_render_params){&(scop->camera), &(scop->projection_m), NULL};
	glClearColor(0.f, 0.6f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	render_objs(&(scop->objects), &params, NULL);
}

/*
** ========================================================================== **
** Main
*/

static void		handle_input(t_scop *scop, float elapsed)
{
	t_vec3			pos;
	t_vec2			look;

	pos = scop->camera.position;
	if (handle_key_hold(scop, elapsed, &pos))
		camera_move(&(scop->camera), pos);
	look = scop->camera.look;
	if (handle_cursor_move(scop, &look))
		camera_look(&(scop->camera), look);
}

int				main(void)
{
	t_scop			scop;
	t_fps			fps;
	int				last_flags;

	ft_bzero(&scop, sizeof(scop));
	scop.objects = VECTOR(t_obj*);
	scop.camera = CAMERA(VEC3_0(), VEC2_0());
	scop.projection_m = ft_mat4perspective(PERSPECTIVE_FOV, WIN_RATIO,
		PERSPECTIVE_NEAR, PERSPECTIVE_FAR);
	camera_move(&(scop.camera), VEC3(-57.2f, -6.7f, 10.6f));
	camera_look(&(scop.camera), VEC2(2.9f, 0.01f));
	if (!init_window(&scop) || !load_scene(&scop))
		return (1);
	glfwSwapInterval(0); // TODO: tmp
	init_events(scop.window);
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
			ft_printf("\rFPS: %-2lld t: %-3lld flags: %.16b "
				"pos: [ %f, %f, %f ] look: [ %f, %f ]%5 %!",
				fps.average_fps, fps.average_time, scop.flags,
				scop.camera.position.x, scop.camera.position.y,
				scop.camera.position.z, scop.camera.look.x, scop.camera.look.y);
		}
		handle_input(&scop, fps.elapsed);
		anim(&scop);
	}
	ft_printf("\n%!");
	glfwTerminate();
	return (0);
}
