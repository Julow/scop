/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/04 14:40:48 by jaguillo         ###   ########.fr       */
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
** Scene
*/

#include "ft/file_in.h"

static bool		load_objs(t_mesh_render *mesh_render, t_vector const *pods,
					t_vector *dst);

static bool		load_obj(t_mesh_render *mesh_render,
					t_scene_pod_object const *pod, t_obj *dst)
{
	t_scene_pod_component const	*comp;

	*dst = OBJ();
	obj_translate(dst, pod->pos);
	obj_rotate(dst, pod->rot);
	obj_scale(dst, pod->scale);
	obj_shear(dst, pod->shear);
	dst->renderer = create_mesh_renderer(mesh_render, load_mesh(*pod->mesh));
	comp = VECTOR_IT(pod->components);
	ft_vreserve(&dst->components, pod->components.length);
	while (VECTOR_NEXT(pod->components, comp))
	{
		if ((*(t_obj_component**)ft_vpush(&dst->components, NULL, 1) =
				comp->c->create(comp->param)) == NULL)
			return (false); // TODO: leaks
	}
	return (load_objs(mesh_render, &pod->childs, &dst->childs));
}

static bool		load_objs(t_mesh_render *mesh_render, t_vector const *pods,
					t_vector *dst)
{
	t_scene_pod_object const	*obj;

	*dst = VECTOR(t_obj);
	ft_vreserve(dst, pods->length);
	obj = VECTOR_IT(*pods);
	while (VECTOR_NEXT(*pods, obj))
	{
		if (!load_obj(mesh_render, obj, ft_vpush(dst, NULL, 1)))
			return (false); // TODO: leaks
	}
	return (true);
}

static bool		load_camera(t_scene_pod_camera const *pod, t_scop *scop)
{
	scop->camera = CAMERA(pod->pos, pod->dir);
	scop->projection_m = ft_mat4perspective(pod->fov, WIN_RATIO,
			pod->near, pod->far);
	return (true);
}

bool			load_scene(t_scop *scop)
{
	t_file_in *const	in = ft_in_fdopen(0);
	t_scene_pod			scene;
	bool				r;

	r = load_scene_pod(V(in), &scene);
	ft_in_close(in);
	if (!r)
		return (false);
	return (load_camera(&scene.camera, scop)
		&& load_objs(&scop->mesh_render, &scene.objects, &scop->objects));
}

/*
** ========================================================================== **
** Render obj
*/

static void		render_objs(t_vector *objs)
{
	t_obj				*obj;

	obj = VECTOR_IT(*objs);
	while (VECTOR_NEXT(*objs, obj))
	{
		if (obj->renderer != NULL)
			obj->renderer->render(obj->renderer, &obj->world_m);
		if (obj->childs.length > 0)
			render_objs(&(obj->childs));
	}
}

void			render(t_scop *scop)
{
	scop->mesh_render.view = camera_get_view(&scop->camera);
	scop->mesh_render.proj = &scop->projection_m;
	scop->mesh_render.camera_pos = scop->camera.position;

	glClearColor(0.f, 0.6f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	render_objs(&scop->objects);
}

/*
** ========================================================================== **
** Update obj
*/

void			update(t_scop *scop)
{
	obj_update(&scop->objects);
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
