/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 17:04:22 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 17:06:53 by jaguillo         ###   ########.fr       */
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
	glBufferData(GL_ARRAY_BUFFER, data->vbo_data.length * sizeof(t_mesh_vbo_data), data->vbo_data.data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->ebo_data.length * sizeof(t_mesh_ebo_data), data->ebo_data.data, GL_STATIC_DRAW);
	mesh->count = data->ebo_data.length * sizeof(t_mesh_ebo_data) / sizeof(int);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(t_mesh_vbo_data), (void*)offsetof(t_mesh_vbo_data, pos));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(t_mesh_vbo_data), (void*)offsetof(t_mesh_vbo_data, col));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(t_mesh_vbo_data), (void*)offsetof(t_mesh_vbo_data, tex));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(t_mesh_vbo_data), (void*)offsetof(t_mesh_vbo_data, nor));
	glEnableVertexAttribArray(3);
	glBindVertexArray(0);
	return (true);
}
