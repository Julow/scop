/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtllib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:27:38 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 15:30:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

t_mtl const		*mtllib_get(t_mtllib const *lib, t_sub name)
{
	t_mtllib_mtl const *const	mtl = ft_set_cget(&lib->mtls, &name);

	return ((mtl == NULL) ? NULL : &mtl->mtl);
}
