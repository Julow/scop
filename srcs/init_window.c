/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 11:50:07 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/26 22:54:50 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

#ifdef MAC_OS_MODE
# define INIT_GLEW			true
# define OPENGL_PROFILE		GLFW_OPENGL_CORE_PROFILE
#else
# define INIT_GLEW			(glewInit() == GLEW_OK)
# define OPENGL_PROFILE		GLFW_OPENGL_COMPAT_PROFILE
#endif

t_bool			init_window(t_scop *scop)
{
	if (glfwInit() != GL_TRUE)
		return (ft_printf("Error: Cannot init GLFW"), false);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, OPENGL_PROFILE);
	if ((scop->window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE,
		NULL, NULL)) == NULL)
		return (glfwTerminate(), ft_printf("Error: Cannot init window"), false);
	glfwMakeContextCurrent(scop->window);
	if (!INIT_GLEW)
		return (ft_printf("Error: Cannot init GLEW"), false);
	glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);
	glEnable(GL_DEPTH_TEST);
	return (true);
}
