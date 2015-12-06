/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 11:54:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:39:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_LOADER_H
# define TEXTURE_LOADER_H

# include "ft/libft.h"
# include "texture.h"

/*
** Load a texture from a file
** -
** Return NULL on error
*/
t_texture const	*load_texture(t_sub file_name);

#endif
