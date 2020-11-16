/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_step2_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:56:16 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/16 11:56:24 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_step2_f(t_ps *ps)
{
	t_dllist	*end;

	end = ft_dllst_end(ps->b);
	if (ps->b != end)
	{
		if (ps->b->n < ps->b->next->n)
		{
			ft_move(ps, 12);
		}
		while (ps->b->n < end->n)
		{
			ft_move(ps, 42);
			end = ft_dllst_end(ps->b);
		}
		ps->b = ft_dllst_begin(ps->b);
	}
}

int			ps_step2_top(t_ps *ps, int m)
{
	ps->b = ft_dllst_begin(ps->b);
	if (ps->b->n < m)
		return (0);
	ps_step2_f(ps);
	ps->b->chunk = ps->chunk;
	ft_move(ps, 21);
	return (1);
}

int			ps_step2_bottom(t_ps *ps, int m)
{
	t_dllist	*end;

	end = ft_dllst_end(ps->b);
	ps->b = ft_dllst_begin(ps->b);
	if (end->n < m)
		return (0);
	ft_move(ps, 42);
	return (1);
}

int			ps_step2_sec_end(t_ps *ps, int m)
{
	t_dllist	*end;

	ps->b = ft_dllst_begin(ps->b);
	end = ft_dllst_end(ps->b);
	if (ps->b == end)
		return (0);
	if (ps->b->next->n >= m && ps->b->next->n > end->n)
		ft_move(ps, 32);
	else
		return (0);
	return (ps_step2_top(ps, m));
}

void		ps_step2(t_ps *ps, int m)
{
	int		i;

	ps->chunk++;
	i = 1;
	while (i && ps->b)
	{
		if (ps_step2_top(ps, m))
			i = 1;
		else if ((ps_step2_sec_end(ps, m)))
			i = 1;
		else if (ps_step2_bottom(ps, m))
			i = 1;
		else if (ps_step2_ra_rra(ps, m))
			i = 1;
		else
			i = 0;
	}
}
