/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/21 15:03:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "ft/math_mat4.h"
#include "ft/math_vec3.h"

#include "anim.h"
#include "anim_component.h"
#include "events.h"
#include "main.h"
#include "mesh.h"
#include "mesh_loader.h"
#include "mesh_renderer.h"
#include "obj.h"
#include "scene_loader.h"
#include "scene_pod.h"
#include "shader.h"
#include "utils.h"

#include <math.h>
#include <stdlib.h>

/*
** ========================================================================== **
** Debug
*/

#define PRINT(I,F,...)		ft_printf("%.*c" F, (I) * 2, ' ', ##__VA_ARGS__)

static void	print_scene_pod_components(t_vector const *components, uint32_t indent)
{
	t_scene_pod_component const	*c;

	c = VECTOR_IT(*components);
	while (VECTOR_NEXT(*components, c))
	{
		PRINT(indent, "- %ts%n", c->name);
	}
}

static void	print_scene_pod_objects(t_vector const *objects, uint32_t indent)
{
	t_scene_pod_object const	*obj;

	obj = VECTOR_IT(*objects);
	while (VECTOR_NEXT(*objects, obj))
	{
		PRINT(indent, "-%n");
		PRINT(indent + 1, "pos: [ %f, %f, %f ]%n", obj->pos.x, obj->pos.y, obj->pos.z);
		PRINT(indent + 1, "rot: [ %f, %f, %f ]%n", obj->rot.x, obj->rot.y, obj->rot.z);
		PRINT(indent + 1, "shear: [ %f, %f, %f ]%n", obj->shear.x, obj->shear.y, obj->shear.z);
		PRINT(indent + 1, "scale: [ %f, %f, %f ]%n", obj->scale.x, obj->scale.y, obj->scale.z);
		PRINT(indent + 1, "components:%n");
		print_scene_pod_components(&obj->components, indent + 2);
		PRINT(indent + 1, "childs:%n");
		print_scene_pod_objects(&obj->childs, indent + 2);
	}
}

static void	print_scene_pod_camera(t_scene_pod_camera const *cam, uint32_t indent)
{
	PRINT(indent, "pos: [ %f, %f, %f ]%n", cam->pos.x, cam->pos.y, cam->pos.z);
	PRINT(indent, "dir: [ %f, %f, %f ]%n", cam->dir.x, cam->dir.y, cam->dir.z);
	PRINT(indent, "fov: %f%n", cam->fov);
	PRINT(indent, "near: %f%n", cam->near);
	PRINT(indent, "far: %f%n", cam->far);
}

static void	print_scene_pod(t_scene_pod const *scene)
{
	ft_printf("objects:%n");
	print_scene_pod_objects(&scene->objects, 1);
	ft_printf("camera:%n");
	print_scene_pod_camera(&scene->camera, 1);
}

/*
** ========================================================================== **
** Scene
*/

typedef struct s_scene_obj		t_scene_obj;
typedef struct s_scene_anim		t_scene_anim;

struct	s_scene_anim
{
	t_vec3			from;
	t_vec3			to;
	float			duration;
	t_obj_anim_t	type;
	float			(*smooth)(float);
	uint32_t		flags;
};

struct	s_scene_obj
{
	t_sub			mesh;
	t_scene_anim	anim;
	t_transform		transform;
	t_scene_obj		*childs;
	int				child_count;
};

#define TRANSFORM(p,o,r,h,s,f)	((t_transform){VEC3 p,VEC3 r,VEC3 h,VEC3 s})
#define TRANSFORM0()			((0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0)
#define SCENE_ANIM(T,D,F,B,E,S)	((t_scene_anim){VEC3 B, VEC3 E, D, OBJ_ANIM_##T, S, F})
#define S_OBJ(m,a,t,c)			((t_scene_obj){SUBC(m),SCENE_ANIM a,TRANSFORM t,(t_scene_obj*)c,(c == NULL) ? 0 : ARRAY_LEN(c)})

static const t_scene_obj	g_scene[] = {
	S_OBJ(NULL, (TRANSLATE, 1800, F_ANIM_REVERSE, (0.f, 0.f, 0.f), (10.f, 0.f, 10.f), &smooth_linear), TRANSFORM0(), ((t_scene_obj[]){
		S_OBJ("res/obj/cube.obj", (TRANSLATE, 0, 0, (0.f, -15.f, 0.f), (0.f, -15.f, 0.f), &smooth_linear), ((0.f, -15.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (100.f, 10.f, 100.f), 0), NULL),
		S_OBJ("res/obj/cube.obj", (SCALE, 1000, F_ANIM_REVERSE, (1.5f, 0.5f, 1.0f), (1.f, 1.f, 1.f), &smooth_elastic),
			((0.f, -5.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0), NULL),
	})),
	S_OBJ("res/obj/42.obj", (SCALE, 1000, F_ANIM_REVERSE, (1.5f, 0.5f, 1.0f), (1.f, 1.f, 1.f), &smooth_elastic), ((-20.f, 0.f, 5.f), (0.f, 0.f, 0.f), (1.f, 0.2f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0), NULL),
	// S_OBJ("res/obj/42.obj", ANIM_SCALE(1200, F_ANIM_REPEAT, (0.8f, 0.8f, 0.8f), (2.f, 2.f, 2.f), &smooth_elastic), ((-20.f, 0.f, 5.f), (0.f, 0.f, 0.f), (1.f, 0.2f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0)),
	// S_OBJ("res/obj/cube.obj", NULL, ((20.f, 0.f, 20.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0)),
	// S_OBJ("res/obj/cube.obj", NULL, ((-700.f, 120.f, -750.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0)),
	S_OBJ("res/obj/teapot.obj", (ROTATE, 2000, F_ANIM_RESTART, (0.f, 0.f, 0.f), (M_PI * 2.f, M_PI * 2.f, M_PI * 2.f), &smooth_linear), ((-35.f, 10.f, 0.f), (5.f, 5.f, 5.f), (0.f, M_PI / 2.f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0), NULL),
	// S_OBJ("res/obj/teapot2.obj", ANIM_MOVE(1800, F_ANIM_RESTART, (10.f, -10.f, 0.f), (10.f, 10.f, 0.f), &smooth_bounce), ((-40.f, -5.f, -5.f), (0.f, 0.f, 0.f), (0.f, 2.f, 0.f), (0.f, 0.f, 0.f), (0.5f, 0.5f, 0.5f), 0)),
	// S_OBJ("res/obj/teapot2.obj", ANIM_MOVE(1800, F_ANIM_REPEAT, (20.f, -10.f, 0.f), (20.f, 10.f, 0.f), &smooth_bounce), ((-40.f, -5.f, -5.f), (0.f, 0.f, 0.f), (0.f, 2.f, 0.f), (0.f, 0.f, 0.f), (0.5f, 0.5f, 0.5f), 0)),
	// S_OBJ("res/obj/teapot2.obj", ANIM_MOVE(1800, F_ANIM_REVERSE, (0.f, -10.f, 0.f), (0.f, 10.f, 0.f), &smooth_bounce), ((-40.f, -5.f, -5.f), (0.f, 0.f, 0.f), (0.f, 2.f, 0.f), (0.f, 0.f, 0.f), (0.5f, 0.5f, 0.5f), 0)),
	// S_OBJ("res/obj/cube.obj", ANIM_SHEAR(4000, F_ANIM_REPEAT, (0.5f, 0.f, 0.f), (-0.5f, 0.5f, -0.5f), &smooth_in_out), ((300.f, -10.f, -50.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.5f, 0.5f), (50.f, 50.f, 50.f), 0)),
	// S_OBJ("res/obj/venice.obj", NULL, ((0.f, -40.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), (1.f, 1.f, 1.f), 0)),
};

static void		load_obj(t_mesh_render *mesh_render, t_vector *dst,
					t_scene_obj const *data, uint32_t count)
{
	uint32_t		i;
	t_obj			*obj;
	t_obj_component	*comp;

	ft_vreserve(dst, count);
	i = 0;
	while (i < count)
	{
		obj = ft_vpush(dst, NULL, 1);
		*obj = OBJ();
		if (data[i].mesh.str != NULL)
			obj->renderer = create_mesh_renderer(mesh_render, load_mesh(data[i].mesh));
		comp = create_anim_component(data[i].anim.from, data[i].anim.to,
			data[i].anim.duration, data[i].anim.smooth, data[i].anim.type,
			data[i].anim.flags);
		ft_vpush(&obj->components, &comp, 1);
		if (data[i].child_count > 0)
			load_obj(mesh_render, &obj->childs, data[i].childs, data[i].child_count);
		obj_translate(obj, data[i].transform.position);
		obj_rotate(obj, data[i].transform.rotation);
		obj_scale(obj, data[i].transform.scale);
		obj_shear(obj, data[i].transform.shear);
		i++;
	}
}

bool			load_scene(t_scop *scop)
{
	load_obj(&scop->mesh_render, &scop->objects, g_scene, ARRAY_LEN(g_scene));
	return (true);
}

/*
** ========================================================================== **
** Render obj
*/

static void		render_objs(t_vector *objs, t_mat4 const *parent_mat)
{
	t_obj				*obj;
	t_mat4				mat;

	obj = VECTOR_IT(*objs);
	while (VECTOR_NEXT(*objs, obj))
	{
		ft_mat4mult(obj_matrix(obj), parent_mat, &mat);
		if (obj->renderer != NULL)
			obj->renderer->render(obj->renderer, &mat);
		if (obj->childs.length > 0)
			render_objs(&(obj->childs), &mat);
	}
}

static t_mat4 const		g_mat4_identity = MAT4_I();

void			render(t_scop *scop)
{
	scop->mesh_render.view = camera_get_view(&scop->camera);
	scop->mesh_render.proj = &scop->projection_m;
	scop->mesh_render.camera_pos = scop->camera.position;

	glClearColor(0.f, 0.6f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	render_objs(&scop->objects, &g_mat4_identity);
}

/*
** ========================================================================== **
** Update obj
*/

static void		update_objs(t_vector *objs)
{
	t_obj				*obj;
	t_obj_component		**component;

	obj = VECTOR_IT(*objs);
	while (VECTOR_NEXT(*objs, obj))
	{
		component = VECTOR_IT(obj->components);
		while (VECTOR_NEXT(obj->components, component))
			(*component)->update(*component, obj);
		if (obj->childs.length > 0)
			update_objs(&obj->childs);
	}
}

void			update(t_scop *scop)
{
	update_objs(&scop->objects);
}

/*
** ========================================================================== **
** Main
*/

#include "ft/file_in.h"

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
	t_file_in *const	in = ft_in_fdopen(0);
	t_scene_pod			scene;

	if (!load_scene_pod(V(in), &scene))
		return (1);

	print_scene_pod(&scene);

	return (0);

	t_scop			scop;
	t_fps			fps;
	int				last_flags;

	ft_bzero(&scop, sizeof(scop));
	scop.objects = VECTOR(t_obj);
	scop.camera = CAMERA(VEC3_0(), VEC2_0());
	scop.projection_m = ft_mat4perspective(PERSPECTIVE_FOV, WIN_RATIO,
		PERSPECTIVE_NEAR, PERSPECTIVE_FAR);
	camera_move(&(scop.camera), VEC3(-57.2f, -6.7f, 10.6f));
	camera_look(&(scop.camera), VEC2(2.9f, 0.01f));
	if (!init_window(&scop) || !load_scene(&scop))
		return (1);
	mesh_render_init(&scop.mesh_render);
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
		update(&scop);
	}
	ft_printf("\n%!");
	glfwTerminate();
	return (0);
}
