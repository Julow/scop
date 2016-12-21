/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_loader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:54:41 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/21 14:59:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_LOADER_H
# define SCENE_LOADER_H

# include "ft/ft_in.h"
# include "ft/libft.h"

# include "scene_pod.h"

/*
** ========================================================================== **
** Scene loader
*/

/*
** Load scene_pod from a json file
** Return true on success, false on error
*/
bool		load_scene_pod(t_in *in, t_scene_pod *dst);

#endif
