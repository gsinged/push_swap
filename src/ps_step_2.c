/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_step_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:44:23 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/13 21:44:24 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ps_step_rb(t_ps *ps, int m)
{
	t_dllist	*a;
	int			i;

	i = 1;
	a = ft_dllst_begin(ps->b);
	while (a && a->n < m)
	{
		a = a->next;
		i++;
	}
	if (a && a->n >= m)
		return (i);
	return (0);
}

int			ps_step_rrb(t_ps *ps, int m)
{
	t_dllist	*end;
	int			i;

	i = 1;
	end = ft_dllst_end(ps->b);
	while (end && end->n < m)
	{
		end = end->prev;
		i++;
	}
	if (end && end->n >= m)
		return (i);
	return (0);
}

void		ps_step2_ra_rra_b(t_ps *ps, int n)
{
	t_dllist	*a;
	t_dllist	*b;

	a = ft_dllst_get_top_n(ps->b, n + 1);
	b = ft_dllst_get_bottom_n(ps->b, n);
	if (a->n > b->n)
	{
		while (n-- > 0)
			ft_move(ps, 32);
	}
	else
	{
		while (n-- > 0)
			ft_move(ps, 42);
	}
}

int			ps_step2_ra_rra(t_ps *ps, int m)
{
	int		top;
	int		bottom;

	top = ps_step_rb(ps, m);
	top > 1 ? top-- : 0;
	bottom = ps_step_rrb(ps, m);
	if (!top && !bottom)
		return (0);
	else if ((top && !bottom) || (top < bottom && top != 0))
	{
		while (top-- > 0)
			ft_move(ps, 32);
	}
	else if ((!top && bottom) || (bottom < top && bottom != 0))
	{
		while (bottom-- > 0)
			ft_move(ps, 42);
	}
	else if (top == bottom)
		ps_step2_ra_rra_b(ps, top);
	return (1);
}

void		ps_step_2(t_ps *ps)
{
	int		m;
	int		ch;

	ch = ft_dllst_max_chunk(ps->b);
	m = ft_dllst_medium_n_chunk(ps->b, ch);
	ps_step2(ps, m);
}
