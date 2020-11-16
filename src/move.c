/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:54:39 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/16 11:54:42 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_push_move(t_ps *ps)
{
	if (ps->last == 11)
		ft_putstr("sa\n");
	else if (ps->last == 12)
		ft_putstr("sb\n");
	else if (ps->last == 13)
		ft_putstr("ss\n");
	else if (ps->last == 21)
		ft_putstr("pa\n");
	else if (ps->last == 22)
		ft_putstr("pb\n");
	else if (ps->last == 31)
		ft_putstr("ra\n");
	else if (ps->last == 32)
		ft_putstr("rb\n");
	else if (ps->last == 33)
		ft_putstr("rr\n");
	else if (ps->last == 41)
		ft_putstr("rra\n");
	else if (ps->last == 42)
		ft_putstr("rrb\n");
	else if (ps->last == 43)
		ft_putstr("rrr\n");
	if (ps->view)
		ft_ps_print_ab(ps);
}

void			ft_move_n(t_ps *ps, int m)
{
	if (m == 11)
		move_sa(ps);
	else if (m == 12)
		move_sb(ps);
	else if (m == 13)
		move_ss(ps);
	else if (m == 21)
		move_pa(ps);
	else if (m == 22)
		move_pb(ps);
	else if (m == 31)
		move_ra(ps);
	else if (m == 32)
		move_rb(ps);
	else if (m == 33)
		move_rr(ps);
	else if (m == 41)
		move_rra(ps);
	else if (m == 42)
		move_rrb(ps);
	else if (m == 43)
		move_rrr(ps);
}

int				ft_moves_exc(t_ps *ps, int m)
{
	if (!ps->last || ps->last == m)
		return (0);
	if (ps->last / 10 == m / 10)
	{
		if (m / 10 == 2)
		{
			ft_move_n(ps, m);
			ps->last = 0;
		}
		else
		{
			ft_move_n(ps, m);
			ps->last = (m / 10) * 10 + 3;
			ft_push_move(ps);
		}
		return (1);
	}
	return (0);
}

void			ft_move(t_ps *ps, int op)
{
	if (!ft_moves_exc(ps, op))
	{
		if (ps->last)
			ft_push_move(ps);
		ft_move_n(ps, op);
		ps->last = op;
	}
}
