/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 17:04:22 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/21 17:51:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/gl.h"
#include "internal.h"

#define VERTEX_SIZE		S(float, 8)
#define OFFSET(n)		(void*)S(float, n)

bool			send_mesh(t_mesh_data *data, t_mesh *mesh)
{
	glGenVertexArrays(1, &(mesh->vao));
	glGenBuffers(1, &(mesh->vbo));
	glGenBuffers(1, &(mesh->ebo));
	glBindVertexArray(mesh->vao);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->vbo);
	glBufferData(GL_ARRAY_BUFFER, S(float, data->vbo_data.length),
		data->vbo_data.data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, S(uint32_t, data->ebo_data.length),
		data->ebo_data.data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, OFFSET(0));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, VERTEX_SIZE, OFFSET(3));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, OFFSET(5));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);
	return (true);
}
