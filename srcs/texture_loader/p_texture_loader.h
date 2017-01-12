/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture_loader.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:40:20 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 15:40:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_TEXTURE_LOADER_H
# define P_TEXTURE_LOADER_H

# include "ft/set.h"

# include "texture.h"
# include "texture_loader.h"

typedef struct s_cached_texture		t_cached_texture;

/*
** ========================================================================== **
*/

struct			s_cached_texture
{
	t_set_h			set_head;
	t_sub			file_name;
	t_texture		texture;
};

#endif
