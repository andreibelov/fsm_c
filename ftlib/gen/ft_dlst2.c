/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:27:09 by abelov            #+#    #+#             */
/*   Updated: 2023/12/30 01:27:12 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dnode	*ft_dlist_pop(t_dlist_info *list)
{
	t_dnode	*elem;
	t_dnode	*next;

	if (!list)
		return (NULL);
	elem = NULL;
	if (list->head)
	{
		elem = list->head;
		next = elem->next;
		if(next)
			next->prev = NULL;
		list->head = next;
		elem->next = NULL;
		elem->prev = NULL;
	}
	return (elem);
}

t_dnode	*ft_dlist_pop_back(t_dlist_info *list)
{
	t_dnode	*elem;
	t_dnode	*prev;

	if (!list)
		return (NULL);
	elem = NULL;
	if (list->tail)
	{
		elem = list->tail;
		prev = elem->prev;
		prev->next = NULL;
		list->tail = prev;
		elem->next = NULL;
		elem->prev = NULL;
	}
	return (elem);
}

t_dlist_info	*ft_dlist_push_back(t_dlist_info *list, t_dnode *dnode)
{
	list->size++;
	if (list->head && list->tail)
	{
		list->tail->next = dnode;
		dnode->prev = list->tail;
		list->tail = dnode;
		return (list);
	}
	dnode->prev = NULL;
	dnode->next = NULL;
	list->head = dnode;
	list->tail = dnode;
	return (list);
}

t_dlist_info	*ft_dlist_append(t_dlist_info *list, int value)
{
	t_dnode	*new_dnode;

	if (!list)
		return (NULL);
	new_dnode = ft_dnode_new(value);
	if (!new_dnode)
		return (NULL);
	return (ft_dlist_push_back(list, new_dnode));
}

t_dlist_info	*ft_dlist_push(t_dlist_info *list, t_dnode *dnode)
{
	list->size++;
	if (list->head && list->tail)
	{
		list->head->prev = dnode;
		dnode->next = list->head;
		list->head = dnode;
		return (list);
	}
	list->head = dnode;
	list->tail = dnode;
	return (list);
}
