/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listremove_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 15:23:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/22 08:24:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_list.h"

void			ft_listremove_next(t_list *lst, void *node, int n)
{
	while ((node = LIST_NEXT(node)) && n-- != 0)
		node = ft_listremove(lst, node);
}
