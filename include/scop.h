/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 12:49:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/15 15:11:22 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libft.h"

# define GLFW_INCLUDE_GLCOREARB
# include <GLFW/glfw3.h>

# define WIN_WIDTH		500
# define WIN_HEIGHT		400

# define WIN_TITLE		"Scop"

typedef struct	s_scop
{
	GLFWwindow		*window;
	t_uint			test_shaders;
}				t_scop;

/*
** create_shader.c
*/
t_bool			create_shader(char const *vert, char const *frag, t_uint *p);

/*
** window.c
*/
t_bool			init_window(t_scop *scop);

/*
** callback.c
*/
void			init_callback(t_scop *scop);

#endif
