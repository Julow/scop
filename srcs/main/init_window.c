/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 11:50:07 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/13 22:08:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "utils.h"

#ifdef MAC_OS_MODE
# define INIT_GLEW			true
# define OPENGL_PROFILE		GLFW_OPENGL_CORE_PROFILE
#else
# define INIT_GLEW			(glewInit() == GLEW_OK)
# define OPENGL_PROFILE		GLFW_OPENGL_COMPAT_PROFILE
#endif
#ifdef GLFW_DOUBLEBUFFER
# define HINT_DOUBLE_BUFFER	true
#else
# define GLFW_DOUBLEBUFFER	0
# define HINT_DOUBLE_BUFFER	false
#endif

static bool		init_glfw(t_scop *scop)
{
	if (glfwInit() != GL_TRUE)
		return (ft_error(false, "Cannot init GLFW"));
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	if (HINT_DOUBLE_BUFFER)
		glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, OPENGL_PROFILE);
	if ((scop->window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE,
		NULL, NULL)) == NULL)
	{
		glfwTerminate();
		return (ft_error(false, "Cannot init window"));
	}
	glfwMakeContextCurrent(scop->window);
	glfwSetInputMode(scop->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	return (true);
}

static bool		init_gl(t_scop *scop)
{
	glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	return (true);
	(void)scop;
}

bool			init_window(t_scop *scop)
{
	if (!init_glfw(scop))
		return (false);
	glfwSetWindowUserPointer(scop->window, scop);
	if (!INIT_GLEW)
		return (ft_error(false, "Cannot init GLEW"));
	if (!init_gl(scop))
		return (false);
	return (true);
}
