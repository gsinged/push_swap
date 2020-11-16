/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_doubly_linked_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:24:36 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/09 22:24:37 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_dllist		*ft_dllst_new(int n)
{
	t_dllist	*new;

	if (!(new = (t_dllist*)malloc(sizeof(t_dllist))))
		return (NULL);
	ft_bzero(new, sizeof(t_dllist));
	new->n = n;
	return (new);
}

void			ft_dllst_insert_before(t_dllist *lst, t_dllist *new)
{
	new->next = lst;
	new->prev = lst->prev;
	if (lst->prev)
		lst->prev->next = new;
	lst->prev = new;
}

void			ft_dllst_insert_after(t_dllist *lst, t_dllist *new)
{
	new->next = lst->next;
	new->prev = lst;
	if (lst->next)
		lst->next->prev = new;
	lst->next = new;
}

void			ft_dllst_insert_begin(t_dllist **lst0, t_dllist *new)
{
	t_dllist	*lst;

	if (*lst0 && new)
	{
		lst = *lst0;
		while (lst->prev)
			lst = lst->prev;
		ft_dllst_insert_before(lst, new);
	}
	*lst0 = new;
}

void			ft_dllst_insert_end(t_dllist **lst0, t_dllist *new)
{
	t_dllist	*lst;

	if (*lst0 && new)
	{
		lst = *lst0;
		while (lst->next)
			lst = lst->next;
		ft_dllst_insert_after(lst, new);
	}
	else
		*lst0 = new;
}
