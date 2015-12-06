/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 13:29:46 by juloo             #+#    #+#             */
/*   Updated: 2015/12/06 13:30:59 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_LOADER_H
# define IMAGE_LOADER_H

# include "ft/ft_image_loader.h"
# include "ft/ft_in.h"

typedef struct	s_imgtype
{
	t_sub			ext;
	t_bool			(*f)(t_in *in, t_img *dst);
}				t_imgtype;

t_bool			load_tga_image(t_in *in, t_img *dst);

#endif
