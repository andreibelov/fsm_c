/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:29:15 by abelov            #+#    #+#             */
/*   Updated: 2023/12/30 01:29:16 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist_info	*ft_dlist_prepend(t_dlist_info *list, int value)
{
	t_dnode	*new_dnode;

	if (!list)
		return (NULL);
	new_dnode = ft_dnode_new(value);
	if (!new_dnode)
		return (NULL);
	return (ft_dlist_push(list, new_dnode));
}

/**
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 */
t_dlist_info	*ft_dlist_rotate(t_dlist_info *list)
{
	if (!list)
		return (NULL);
	if (list->head)
		ft_dlist_push_back(list, ft_dlist_pop(list));
	return (list);
}

/**
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 */
t_dlist_info	*ft_dlist_rev_rotate(t_dlist_info *list)
{
	if (!list)
		return (NULL);
	if (list->tail)
		ft_dlist_push(list, ft_dlist_pop_back(list));
	return (list);
}
