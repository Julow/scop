/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/26 13:22:06 by jaguillo         ###   ########.fr       */
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

static void		draw_background(void)
{
	glClearColor(0.f, 0.6f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

static void		draw_obj(t_obj *obj)
{
	glUseProgram(obj->shader->handle);
	glBindTexture(GL_TEXTURE_2D, obj->texture->handle);
	glBindVertexArray(obj->mesh->vao);
	glDrawElements(GL_TRIANGLES, obj->mesh->count, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

int				main(void)
{
	t_scop			scop;
	t_mat4			view_m
	t_mat4			projection_m;
	t_mat4			m;
	int				frames;
	t_ulong			last_fps;
	t_ulong			tmp;

	if (!init_window(&scop))
		return (ft_fdprintf(2, "Error: Cannot init window\n"), 1);
	init_key_events(&scop);
	if (!create_obj(&(scop.test_obj), SUBC("42"), SUBC("wall"), SUBC("test")))
		return (ft_fdprintf(2, "lol\n"), 1);
	view_m = ft_mat4identity();
	ft_mat4translate(&view_m, VEC3(0.f, 0.f, -5.f));
	projection_m = ft_mat4perspective(PERSPECTIVE_FOV, WIN_RATIO,
		PERSPECTIVE_NEAR, PERSPECTIVE_FAR);
	frames = 0;
	last_fps = ft_clock(0);
	while (!glfwWindowShouldClose(scop.window))
	{
		tmp = ft_clock(0);
		if ((tmp - last_fps) >= FPS_INTERVAL)
		{
			ft_printf("FPS: %-4d\r", frames * 1000000 / (tmp - last_fps));
			last_fps = tmp;
			frames = 0;
		}
		frames++;
		glfwPollEvents();
		draw_background();
		m = ft_mat4identity();
		float progress = cosf(((float)(tmp % 5000000)) / 2500000.f * M_PI);
		ft_mat4translate(&m, VEC3(0.f, 0.f, 0.f));
		float scale = progress / M_PI + 0.5f;
		ft_mat4scale(&m, VEC3(scale, scale, scale));
		float rot = progress * 2.f;
		ft_mat4rotate(&m, VEC3(rot - M_PI, rot - M_PI, rot));
		glUniformMatrix4fv(scop.test_obj.shader->model_loc, 1, GL_TRUE, (float*)&m);
		glUniformMatrix4fv(scop.test_obj.shader->view_loc, 1, GL_TRUE, (float*)&view_m);
		glUniformMatrix4fv(scop.test_obj.shader->projection_loc, 1, GL_TRUE, (float*)&projection_m);
		draw_obj(&(scop.test_obj));
		glfwSwapBuffers(scop.window);
	}
	return (glfwTerminate(), 0);
}
