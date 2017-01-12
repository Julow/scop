/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_loader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 10:27:57 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 15:54:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_LOADER_H
# define SHADER_LOADER_H

# include "ft/libft.h"
# include "shader.h"

/*
** Load a shader program
** -
**  // code for all shaders
** //#shader vert
**  // code for vert shader
** //#shader all
**  // code for frag and geom shader
** //#shader frag
**  // code for frag shader
** //#shader geom
**  // code for geom shader
** -
** a //#shader cannot be repeated (except 'all')
** -
** Return false on error
*/
bool			load_shader(t_sub file_name, t_shader *dst);

#endif
