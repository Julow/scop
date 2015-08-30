/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 17:04:22 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/30 15:48:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh_loader.h"
#include "gl.h"

t_bool			send_mesh(t_mesh_data *data, t_mesh *mesh)
{
	glGenVertexArrays(1, &(mesh->vao));
	glGenBuffers(1, &(mesh->vbo));
	glGenBuffers(1, &(mesh->ebo));
	glBindVertexArray(mesh->vao);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->vbo);
	glBufferData(GL_ARRAY_BUFFER, S(float, data->vbo_data.length), data->vbo_data.data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, S(int, data->ebo_data.length), data->ebo_data.data, GL_STATIC_DRAW);
	mesh->count = data->ebo_data.length;
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, S(float, 11), (void*)(S(float, 0)));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, S(float, 11), (void*)(S(float, 3)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, S(float, 11), (void*)(S(float, 6)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, S(float, 11), (void*)(S(float, 8)));
	glEnableVertexAttribArray(3);
	glBindVertexArray(0);
	return (true);
}
