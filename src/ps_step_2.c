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



void		ps_step2_f(t_ps *ps, int m)
{
	t_dllist	*end;

	end = ft_dllst_end(ps->a);
	if (ps->b->n > ps->b->next->n)
	{
		ft_move(ps, 12);
	}
	while (ps->b->n > end->n)
	{
		ft_move(ps, 42);
		end = ft_dllst_end(ps->a);
	}
	ps->b = ft_dllst_begin(ps->b);
}

int			ps_step2_top(t_ps *ps, int m)
{
	ps->b = ft_dllst_begin(ps->b);
	if (ps->b->n >= m)
		return (0);
	ps_step2_f(ps, m);
	ps->b->chunk = ps->chunk;
	ft_move(ps, 21);
	return (1);
}

int			ps_step2_bottom(t_ps *ps, int m)
{
	t_dllist	*end;

	end = ft_dllst_end(ps->b);
	ps->b = ft_dllst_begin(ps->b);
	if (end->n >= m)
		return (0);
	ft_move(ps, 42);
	return (1);
}

int			ps_step2_sec_end(t_ps *ps, int m)
{
	t_dllist	*end;

	ps->b = ft_dllst_begin(ps->b);
	end = ft_dllst_end(ps->b);
	if (ps->b->next->n < m && ps->b->next->n < end->n)
		ft_move(ps, 32);
	else
		return (0);
	return (ps_step2_top(ps, m));
}

int			ps_step_ra_chunk(t_ps *ps, int m, int ch)
{
	t_dllist	*a;
	int			i;

	i = 1;
	a = ft_dllst_begin(ps->b);
	while (a->n >= m && a->chunk == ch)
	{
		a = a->next;
		i++;
	}
	if (a->n < m)
		return (i);
	return (0);
}

int			ps_step_rra_chunk(t_ps *ps, int m, int ch)
{
	t_dllist	*end;
	int			i;

	i = 1;
	end = ft_dllst_end(ps->a);
	while (end->n >= m && end->chunk == ch)
	{
		end = end->prev;
		i++;
	}
	if (end->n < m)
		return (i);
	return (0);
}

void		ps_step2_ra_rra_b(t_ps *ps, int n)
{
	t_dllist	*a;
	t_dllist	*b;

	a = ft_dllst_get_top_n(ps->b, n + 1);
	b = ft_dllst_get_bottom_n(ps->b, n);
	if (a->n < b->n)
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

int			ps_step2_ra_rra(t_ps *ps, int m, int ch)
{
	int		top;
	int		bottom;

	top = ps_step_ra_chunk(ps, m, ch);
	top > 1 ? top-- : 0;
	bottom = ps_step_rra_chunk(ps, m, ch);
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

void		ps_step2_chunk(t_ps *ps, int m, int ch)
{
	int		i;

	ps->chunk++;
	i = 1;
	while (i)
	{
		if (ps_step2_top(ps, m))
			i = 1;
		else if ((ps_step2_sec_end(ps, m)))
			i = 1;
		else if (ps_step2_bottom(ps, m))
			i = 1;
		else if (ps_step2_ra_rra(ps, m, ch))
			i = 1;
		else
			i = 0;
	}
}

void		ps_step_2(t_ps *ps)
{
	int		m;
	int		ch;

	ch = ft_dllst_max_chunk(ps->b);
	m = ft_dllst_medium_n_chunk(ps->b, ch);
	ps_step2_chunk(ps, m, ch);
}
