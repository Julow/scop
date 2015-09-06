/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_loaders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 01:13:56 by juloo             #+#    #+#             */
/*   Updated: 2015/09/06 01:14:52 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources.h"
#include "shader_loader.h"
#include "mesh_loader.h"
#include "mtl_loader.h"
#include "texture_loader.h"

t_bool			shader_res_loader(void *dst, t_res_shader const *res)
{
	return (load_shader(res->vert_file, res->frag_file, dst));
}

t_bool			texture_res_loader(void *dst, t_res_texture const *res)
{
	return (load_texture(res->file, dst));
}

t_bool			mesh_res_loader(void *dst, t_res_mesh const *res)
{
	return (load_mesh(res->file, dst));
}

t_bool			mtl_res_loader(void *dst, t_res_mtl const *res)
{
	return (load_mtl(res->file, dst));
}
