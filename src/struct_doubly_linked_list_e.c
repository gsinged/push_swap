/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_doubly_linked_list_e.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:58:05 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/16 11:58:06 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_dllst_position_min(t_dllist *d, t_dllist **lst)
{
	int			i;
	int			min;
	int			p;
	t_dllist	*c;

	d = ft_dllst_begin(d);
	min = d->n;
	c = d;
	p = 1;
	d = d->next;
	i = 2;
	while (d)
	{
		if (d->n < min)
		{
			min = d->n;
			c = d;
			p = i;
		}
		d = d->next;
		i++;
	}
	if (lst)
		*lst = c;
	return (p);
}

int				ft_dllst_position_max(t_dllist *d, t_dllist **lst)
{
	int			i;
	int			max;
	int			p;
	t_dllist	*c;

	d = ft_dllst_begin(d);
	max = d->n;
	c = d;
	p = 1;
	d = d->next;
	i = 2;
	while (d)
	{
		if (d->n > max)
		{
			max = d->n;
			c = d;
			p = i;
		}
		d = d->next;
		i++;
	}
	if (lst)
		*lst = c;
	return (p);
}

int				ft_dllst_min_n_chunk(t_dllist *a, int ch)
{
	int		min;

	a = ft_dllst_begin(a);
	while (a && a->chunk != ch)
		a = a->next;
	min = a->n;
	while (a)
	{
		if (a->chunk == ch && min > a->n)
			min = a->n;
		a = a->next;
	}
	return (min);
}

int				ft_dllst_max_chunk(t_dllist *a)
{
	int		ch;

	a = ft_dllst_begin(a);
	ch = a->chunk;
	while (a)
	{
		if (ch < a->chunk)
			ch = a->chunk;
		a = a->next;
	}
	return (ch);
}

int				ft_dllst_max_n_chunk(t_dllist *a, int ch)
{
	int		max;

	a = ft_dllst_begin(a);
	while (a && a->chunk != ch)
		a = a->next;
	max = a->chunk;
	while (a)
	{
		if (a->chunk == ch && max < a->n)
			max = a->n;
		a = a->next;
	}
	return (max);
}
