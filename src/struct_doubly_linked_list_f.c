/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_doubly_linked_list_f.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:58:11 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/16 11:58:14 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_dllst_medium_n_b(t_dllist *a, int mid, int *next)
{
	int		i;

	i = 1;
	while (a)
	{
		if (a->n > mid && i)
		{
			*next = a->n;
			i = 0;
		}
		if (a->n > mid)
		{
			if (*next > a->n)
				*next = a->n;
		}
		a = a->next;
	}
}

int				ft_dllst_medium_n(t_dllist *d)
{
	int			mid;
	int			p;
	int			next;
	t_dllist	*a;

	mid = ft_dllst_lenght(d);
	p = mid / 2;
	mid = ft_dllst_min_n(d);
	while (p > 0)
	{
		a = ft_dllst_begin(d);
		ft_dllst_medium_n_b(a, mid, &next);
		mid = next;
		p--;
	}
	return (mid);
}

static void		ft_dllst_medium_n_chu_b(t_dllist *a, int ch, int mid, int *next)
{
	int		i;

	i = 1;
	while (a)
	{
		if (i && a->chunk == ch && a->n > mid)
		{
			*next = a->n;
			i = 0;
		}
		if (a->chunk == ch && a->n > mid)
		{
			if (*next > a->n)
				*next = a->n;
		}
		a = a->next;
	}
}

int				ft_dllst_medium_n_chunk(t_dllist *d, int ch)
{
	int			mid;
	int			p;
	int			next;
	t_dllist	*a;

	mid = ft_dllst_lenght_chunk(d, ch);
	p = mid / 2;
	mid = ft_dllst_min_n_chunk(d, ch);
	while (p > 0)
	{
		a = ft_dllst_begin(d);
		ft_dllst_medium_n_chu_b(a, ch, mid, &next);
		mid = next;
		p--;
	}
	return (mid);
}

int				ft_dllst_lenght_chunk(t_dllist *d, int ch)
{
	int		i;

	d = ft_dllst_begin(d);
	i = 0;
	while (d)
	{
		if (d->chunk == ch)
			i++;
		d = d->next;
	}
	return (i);
}
