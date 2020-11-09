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
}

void			ft_dllst_insert_after(t_dllist *lst, t_dllist *new)
{
	new->next = lst->next;
	new->prev = lst;
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
	else
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

t_dllist		*ft_dllst_begin(t_dllist *cur)
{
	if (!cur)
		return (NULL);
	while (cur->prev)
		cur = cur->prev;
	return (cur);
}

t_dllist		*ft_dllst_end(t_dllist *cur)
{
	if (!cur)
		return (NULL);
	while (cur->next)
		cur = cur->next;
	return (cur);
}

void			ft_dllst_delone(t_dllist **one)
{
	if (one && *one)
	{
		if ((*one)->prev)
			(*one)->prev->next = (*one)->next;
		if ((*one)->next)
			(*one)->next->prev = (*one)->prev;
		ft_bzero(*one, sizeof(t_dllist));
		free(*one);
		*one = NULL;
	}
}

static void		ft_dllst_delete_b(t_dllist **lst)
{
	if (lst && *lst)
	{
		if ((*lst)->next)
			ft_dllst_delete_b(&((*lst)->next));
		ft_bzero(*lst, sizeof(t_dllist));
		free(*lst);
		*lst = NULL;
	}
}

void			ft_dllst_delete(t_dllist **lst)
{
	if (!(*lst)->prev)
	{
		ft_dllst_delete_b(lst);
	}
	else
		ft_dllst_delete_b(&(ft_dllst_begin(*lst)));
}
