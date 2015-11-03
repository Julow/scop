/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 14:21:01 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/03 14:27:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "texture_loader.h"
# include "texture.h"
# include "ft_img.h"

# define TEXTURE_CACHE_SIZE	10

t_texture		*texture_cache_get(char const *file);
void			texture_cache_new(char const *file, t_texture *texture);

#endif
