/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/23 11:28:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "ft/math_mat4.h"
#include "ft/math_vec3.h"

#include "anim.h"
#include "events.h"
#include "main.h"
#include "mesh.h"
#include "mesh_loader.h"
#include "obj.h"
#include "obj_anim.h"
#include "render.h"
#include "shader.h"
#include "utils.h"

#include <math.h>
#include <stdlib.h>

// /*
// ** ========================================================================== **
// ** Component
// */

// typedef struct s_component		t_component;
// typedef struct s_component_bind	t_component_bind;

// struct		s_component
// {
// 	void		(*update)(t_component*);
// };

// struct		s_component_bind
// {
// 	t_component	*component;
// };

// /*
// ** ========================================================================== **
// ** Obj anim component
// */

// typedef t_component						t_anim_component;
// typedef struct s_anim_component_bind	t_anim_component_bind;

// struct			s_anim_component_bind
// {
// 	t_anim			anim;
// 	t_vec3			from;
// 	t_vec3			to;
// };

// void		anim_component_bind(t_anim_component *c, t_obj *obj,
// 				t_anim_component_bind const *bind)
// {
// 	t_component_bind	bind;

// 	bind = (t_component_bind){c};
// }

// void		anim_component_update(t_anim_component *c, t_obj *obj,
// 				t_anim_component_bind *bind)
// {
// 	anim_update(bind, &bind->anim, ft_clock());
// }

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

#define TRANSFORM(p,o,r,h,s,f)	((t_transform){VEC3 p,VEC3 r,VEC3 h,VEC3 s})
#define TRANSFORM0()			((0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0)
#define S_OBJ(m,a,t,c)			((t_scene_obj){SUBC(m),a,TRANSFORM t,(t_scene_obj*)c,(c == NULL) ? 0 : ARRAY_LEN(c)})

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

static void		load_obj(t_vector *dst, t_scene_obj const *data, uint32_t count)
{
	uint32_t		i;
	t_obj			*obj;
	uint32_t const	tmp_capacity = dst->capacity;

	ft_vreserve(dst, count);
	i = 0;
	while (i < count)
	{
		obj = NEW(t_obj);
		ft_vpush(dst, &obj, 1);
		ft_bzero(obj, sizeof(t_obj));
		obj->anim = data[i].anim;
		obj->mesh = (data[i].mesh.str == NULL) ? NULL : load_mesh(data[i].mesh);
		if (obj->anim != NULL)
			anim_start(obj->anim); // TODO: move to scene
		obj->childs = VECTOR(t_obj*);
		load_obj(&obj->childs, data[i].childs, data[i].child_count);
		obj_translate(obj, data[i].transform.position);
		obj_rotate(obj, data[i].transform.rotation);
		obj_scale(obj, data[i].transform.scale);
		obj_shear(obj, data[i].transform.shear);
		i++;
	}
	ft_printf("CAPACITY: %u -> %u%n", tmp_capacity, dst->capacity);
}

bool			load_scene(t_scop *scop)
{
	load_obj(&scop->objects, g_scene, ARRAY_LEN(g_scene));
	return (true);
}

/*
** ========================================================================== **
** Anim obj
*/

static void		anim_objs(t_vector *objs, uint64_t now)
{
	t_obj			*obj;
	uint32_t		i;

	i = 0;
	while (i < objs->length)
	{
		obj = *(t_obj**)VECTOR_GET(*objs, i);
		if (obj->anim != NULL)
			anim_update(obj, obj->anim, now);
		if (obj->childs.length > 0)
			anim_objs(&(obj->childs), now);
		i++;
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

// void			render_objs(t_vector *objs, t_render_params *params)
// {
// 	t_obj			*obj;
// 	uint32_t		i;

// 	i = 0;
// 	while (i < objs->length)
// 	{
// 		obj = *(t_obj**)VECTOR_GET(*objs, i);
// 		params->top_matrix = obj_matrix(obj);
// 		if (obj->mesh != NULL)
// 			simple_render(params, obj->mesh);
// 		if (obj->childs.length > 0)
// 			render_objs(&(obj->childs), params);
// 		i++;
// 	}
// }

// void			render(t_scop *scop)
// {
// 	t_render_params		params;

// 	// ft_mat4mult(&scop->projection_m, camera_get_view(&(scop->camera)), &top_matrix);
// 	// ft_mat4transpose(&top_matrix);
// 	params = (t_render_params){&(scop->camera), &(scop->projection_m), NULL};
// 	glClearColor(0.f, 0.6f, 0.6f, 1.0f);
// 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 	render_objs(&scop->objects, &params);
// }

static void		render_objs(t_vector *objs, t_render_params *params)
{
	t_mat4 const *const	parent_mat = params->top_matrix;
	t_obj				*obj;
	t_mat4				mat;
	uint32_t		i;

	i = 0;
	while (i < objs->length)
	{
		obj = *(t_obj**)VECTOR_GET(*objs, i);
		ft_mat4mult(obj_matrix(obj), parent_mat, &mat);
		params->top_matrix = &mat;
		if (obj->mesh != NULL)
			simple_render(params, obj->mesh);
		if (obj->childs.length > 0)
			render_objs(&(obj->childs), params);
		i++;
	}
}

static t_mat4 const		g_mat4_identity = MAT4_I();

void			render(t_scop *scop)
{
	t_render_params		params;

	params = (t_render_params){
		&(scop->camera),
		&(scop->projection_m),
		&g_mat4_identity
	};
	glClearColor(0.f, 0.6f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	render_objs(&scop->objects, &params);
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
