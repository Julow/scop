/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:20:22 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/28 17:56:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "ft/ft_vector.h"
# include "obj.h"

typedef struct s_scene			t_scene;

/*
** ========================================================================== **
** Scene
*/

struct			s_scene
{
	t_vector		objects;
};

#endif
