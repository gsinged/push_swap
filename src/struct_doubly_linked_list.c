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
	t_dllist	*c;

	if (lst && *lst)
	{
		if (!(*lst)->prev)
		{
			ft_dllst_delete_b(lst);
		}
		else
		{
			c = ft_dllst_begin(*lst);
			ft_dllst_delete_b(&c);
		}
	}
}

t_dllist		*ft_dllst_copy_one(t_dllist *one)
{
	t_dllist	*c;

	if (!one)
		return (NULL);
	if (!(c = ft_dllst_new(one->n)))
		return (NULL);
	return (c);
}

t_dllist		*ft_dllst_copy(t_dllist *a)
{
	t_dllist	*begin;
	t_dllist	*cur;
	t_dllist	*c;

	if (!a)
		return (NULL);
	a = ft_dllst_begin(a);
	if (!(begin = ft_dllst_copy_one(a)))
		return (NULL);
	cur = begin;
	a = a->next;
	while (a)
	{
		if (!(c = ft_dllst_copy_one(a)))
		{
			ft_dllst_delete(&begin);
			return (NULL);
		}
		cur->next = c;
		c->prev = cur;
		cur = cur->next;
		a = a->next;
	}
	return (begin);
}

void			ft_dllst_add_sort(t_dllist *a, t_dllist *new)
{
	a = ft_dllst_begin(a);
	while (a->next != NULL)
	{
		if (new->n <= a->n)
			break ;
		a = a->next;
	}
	if (new->n <= a->n)
		ft_dllst_insert_before(a, new);
	else
		ft_dllst_insert_after(a, new);
}

t_dllist		*ft_dllst_copy_sort(t_dllist *a)
{
	t_dllist	*begin;
	t_dllist	*c;

	if (!a)
		return (NULL);
	a = ft_dllst_begin(a);
	if (!(begin = ft_dllst_copy_one(a)))
		return (NULL);
	a = a->next;
	while (a)
	{
		if (!(c = ft_dllst_copy_one(a)))
		{
			ft_dllst_delete(&begin);
			return (NULL);
		}
		ft_dllst_add_sort(begin, c);
		begin = ft_dllst_begin(begin);
		a = a->next;
	}
	return (begin);
}

int				ft_dllst_lenght(t_dllist *d)
{
	int		i;

	d = ft_dllst_begin(d);
	i = 0;
	while (d)
	{
		i++;
		d = d->next;
	}
	return (i);
}

void		ft_dllst_print(t_dllist *d)
{
	d = ft_dllst_begin(d);
	while (d)
	{
		printf("%d\n", d->n);
		d = d->next;
	}
}
