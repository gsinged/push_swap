/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_step_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:38:50 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/13 21:38:51 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ps_step_ra(t_ps *ps, int m)
{
	t_dllist	*a;
	int			i;

	i = 1;
	a = ft_dllst_begin(ps->a);
	while (a && a->n >= m)
	{
		a = a->next;
		i++;
	}
	if (a && a->n < m)
		return (i);
	return (0);
}

int			ps_step_rra(t_ps *ps, int m)
{
	t_dllist	*end;
	int			i;

	i = 1;
	end = ft_dllst_end(ps->a);
	while (end && end->n >= m)
	{
		end = end->prev;
		i++;
	}
	if (end && end->n < m)
		return (i);
	return (0);
}

void		ps_step1_ra_rra_b(t_ps *ps, int n)
{
	t_dllist	*a;
	t_dllist	*b;

	a = ft_dllst_get_top_n(ps->a, n + 1);
	b = ft_dllst_get_bottom_n(ps->a, n);
	if (a->n < b->n)
	{
		while (n-- > 0)
			ft_move(ps, 31);
	}
	else
	{
		while (n-- > 0)
			ft_move(ps, 41);
	}
}

int			ps_step1_ra_rra(t_ps *ps, int m)
{
	int		top;
	int		bottom;

	top = ps_step_ra(ps, m);
	top > 1 ? top-- : 0;
	bottom = ps_step_rra(ps, m);
	if (!top && !bottom)
		return (0);
	else if ((top && !bottom) || (top < bottom && top != 0))
	{
		while (top-- > 0)
			ft_move(ps, 31);
	}
	else if ((!top && bottom) || (bottom < top && bottom != 0))
	{
		while (bottom-- > 0)
			ft_move(ps, 41);
	}
	else if (top == bottom)
		ps_step1_ra_rra_b(ps, top);
	return (1);
}

void		ps_step_1(t_ps *ps)
{
	int		m;
	int		sort;

	sort = ft_dllst_q_sort(ps->a);
	if (sort == 2)
		ps_step3_sort(ps);
	else if (!sort)
	{
		while (ps->na > 3)
		{
			m = ft_dllst_medium_n(ps->a);
			ps_step1_chunk(ps, m);
		}
	}
}
