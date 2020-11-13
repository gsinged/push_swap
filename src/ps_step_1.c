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

int			ft_three(t_ps *ps)
{
	while (!ft_dllst_q_sort(ps->a))
		ft_move(ps, 11);
	if (ft_dllst_q_sort(ps->a) == 1)
		return (1);
	else
	{
		if (ft_dllst_position_min(ps->a, NULL) == 2)
			ft_move(ps, 31);
		else
			ft_move(ps, 41);
	}
	if (ft_dllst_q_sort(ps->a) == 1)
		return (1);
	return (0);
}

void		ps_step1_f(t_ps *ps, int m)
{
	t_dllist	*end;

	ps->a = ft_dllst_begin(ps->a);
	end = ft_dllst_end(ps->a);
	if (ps->a->n > ps->a->next->n)
	{
		ft_move(ps, 11);
	}
	while (ps->a->n > end->n)
	{
		ft_move(ps, 41);
		end = ft_dllst_end(ps->a);
	}
	ps->a = ft_dllst_begin(ps->a);
}

int			ps_step1_top(t_ps *ps, int m)
{
	ps->a = ft_dllst_begin(ps->a);
	if (ps->a->n >= m)
		return (0);
	ps_step1_f(ps, m);
	ps->a->chunk = ps->chunk;
	ft_move(ps, 22);
	return (1);
}

int			ps_step1_bottom(t_ps *ps, int m)
{
	t_dllist	*end;

	end = ft_dllst_end(ps->a);
	ps->a = ft_dllst_begin(ps->a);
	if (end->n >= m)
		return (0);
	ft_move(ps, 41);
	return (1);
}

int			ps_step1_sec_end(t_ps *ps, int m)
{
	t_dllist	*end;

	ps->a = ft_dllst_begin(ps->a);
	end = ft_dllst_end(ps->a);
	if (ps->a->next->n < m && ps->a->next->n < end->n)
		ft_move(ps, 31);
	else
		return (0);
	return (ps_step1_top(ps, m));
}

int			ps_step_ra(t_ps *ps, int m)
{
	t_dllist	*a;
	int			i;
	int			mid;

	i = 1;
	a = ft_dllst_begin(ps->a);
	mid = ps->na / 2 + 1;
	while (i < mid && a->n >= m)
	{
		a = a->next;
		i++;
	}
	if (a->n < m)
		return (i);
	return (0);
}

int			ps_step_rra(t_ps *ps, int m)
{
	t_dllist	*end;
	int			i;
	int			mid;

	i = 1;
	end = ft_dllst_end(ps->a);
	mid = ps->na / 2;
	while (i < mid && end->n >= m)
	{
		end = end->prev;
		i++;
	}
	if (end->n < m)
		return (i);
	return (0);
}

void		ps_step1_ra_rra_b(t_ps *ps, int n)
{
	t_dllist	*a;
	t_dllist	*b;

	a = ft_dllst_get_top_n(ps->a, n + 1);
	b = ft_dllst_get_bottom_n(ps->a, n);
	if (a < b)
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

void		ps_step1_chunk(t_ps *ps, int m)
{
	int		i;

	ps->chunk++;
	i = 1;
	while (i)
	{
		if (ps_step1_top(ps, m))
			i = 1;
		else if ((ps_step1_sec_end(ps, m)))
			i = 1;
		else if (ps_step1_bottom(ps, m))
			i = 1;
		else if (ps_step1_ra_rra(ps, m))
			i = 1;
		else
			i = 0;
	}
}

void		ps_step_1(t_ps *ps)
{
	int		m;

	while (ps->na > 3)
	{
		m = ft_dllst_medium_n(ps->a);
		ps_step1_chunk(ps, m);
	}
}
