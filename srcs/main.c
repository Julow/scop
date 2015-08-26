/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/26 17:43:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "resources.h"
#include "utils.h"
#include <stdlib.h>
#include <math.h>

#define FPS_INTERVAL		100000

t_bool			create_obj(t_obj *dst, t_sub mesh, t_sub texture, t_sub shader)
{
	if ((dst->mesh = get_res(res_mesh, mesh)) == NULL
		|| (dst->texture = get_res(res_texture, texture)) == NULL
		|| (dst->shader = get_res(res_shader, shader)) == NULL)
		return (false);
	return (true);
}
#include <stdio.h>//
int				main(int argc, char **argv)
{
	t_scop			scop;
	t_mat4			view_m;
	t_mat4			projection_m;
	t_mat4			m;
	int				frames;
	t_ulong			last_fps;
	t_ulong			tmp;

// init
	if (!init_window(&scop))
		return (ft_fdprintf(2, "Error: Cannot init window\n"), 1);
	init_key_events(&scop);
// create test obj
	if ((scop.test_obj.mesh = get_res(res_mesh, (argc > 1) ? ft_sub(argv[1], 0, -1) : SUBC("42"))) == NULL)
		return (ft_printf("Error: Cannot load mesh\n"), 1);
	if ((scop.test_obj.texture = get_res(res_texture, (argc > 2) ? ft_sub(argv[2], 0, -1) : SUBC("wall"))) == NULL)
		return (ft_printf("Error: Cannot load texture\n"), 1);
	if ((scop.test_obj.shader = get_res(res_shader, (argc > 3) ? ft_sub(argv[3], 0, -1) : SUBC("test"))) == NULL)
		return (ft_printf("Error: Cannot load shader\n"), 1);
// proj matrix
	projection_m = ft_mat4perspective(PERSPECTIVE_FOV, WIN_RATIO, PERSPECTIVE_NEAR, PERSPECTIVE_FAR);
// render loop
	frames = 0;
	last_fps = ft_clock(0);
	while (!glfwWindowShouldClose(scop.window))
	{
// count FPS
		tmp = ft_clock(0);
		if ((tmp - last_fps) >= FPS_INTERVAL)
		{
			// ft_printf("FPS: %-4d\r", frames * 1000000 / (tmp - last_fps));
			last_fps = tmp;
			frames = 0;
		}
		frames++;
		float progress = cosf(((float)(tmp % 5000000)) / 2500000.f * M_PI);
		// float progress = 1.f;
// poll events
		glfwPollEvents();
// draw background
		glClearColor(0.f, 0.6f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// view matrix
		t_vec3			camera_pos = VEC3(0.f, 0.f, 0.f);
		t_vec3			camera_look = VEC3(1.f, 0.1f, 0.f);

		// ft_vec3rotate(&camera_look, VEC3((progress +1.f) * M_PI, 0.f, 0.f));
		printf("camera_look $ %f [ %f, %f, %f ]\r", progress, camera_look.x, camera_look.y, camera_look.z);
		fflush(stdout);
		view_m = ft_mat4look_at(camera_pos, camera_look, VEC3(0.f, 1.f, 0.f));
		ft_mat4rotate(&view_m, VEC3(0.f, 0.f, progress));
// model matrix
		progress = 1.f;
		m = ft_mat4identity();
		ft_mat4translate(&m, VEC3(-20.f, 0.f, 5.f));
		float scale = 1.f;
		ft_mat4scale(&m, scale);
		float rot = progress * 2.f;
		ft_mat4rotate(&m, VEC3(rot - M_PI, rot - M_PI, rot));
// uniforms
		glUniformMatrix4fv(scop.test_obj.shader->model_loc, 1, GL_TRUE, (float*)&m);
		glUniformMatrix4fv(scop.test_obj.shader->view_loc, 1, GL_TRUE, (float*)&view_m);
		glUniformMatrix4fv(scop.test_obj.shader->projection_loc, 1, GL_TRUE, (float*)&projection_m);
// draw obj
		glUseProgram(scop.test_obj.shader->handle);
		glBindTexture(GL_TEXTURE_2D, scop.test_obj.texture->handle);
		glBindVertexArray(scop.test_obj.mesh->vao);
		glDrawElements(GL_TRIANGLES, scop.test_obj.mesh->count, GL_UNSIGNED_INT, 0);
// lol
		m = ft_mat4identity();
		ft_mat4translate(&m, VEC3(-20.f, 0.f, 0.f));
		ft_mat4scale(&m, scale);
		rot = progress * 2.f;
		ft_mat4rotate(&m, VEC3(rot - M_PI, rot - M_PI, rot));
		glUniformMatrix4fv(scop.test_obj.shader->model_loc, 1, GL_TRUE, (float*)&m);
		glUniformMatrix4fv(scop.test_obj.shader->view_loc, 1, GL_TRUE, (float*)&view_m);
		glUniformMatrix4fv(scop.test_obj.shader->projection_loc, 1, GL_TRUE, (float*)&projection_m);
		glUseProgram(scop.test_obj.shader->handle);
		glBindTexture(GL_TEXTURE_2D, scop.test_obj.texture->handle);
		glBindVertexArray(scop.test_obj.mesh->vao);
		glDrawElements(GL_TRIANGLES, scop.test_obj.mesh->count, GL_UNSIGNED_INT, 0);
// validate render
		glfwSwapBuffers(scop.window);
	}
	return (glfwTerminate(), 0);
}
