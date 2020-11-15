/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:03:02 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/11 18:03:04 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_push_move_test(t_ps *ps, int op)
{
	if (0)
	{
		ft_printf("============TEST==========\n");
		if (op == 11)
			ft_putstr("sa\n");
		else if (op == 12)
			ft_putstr("sb\n");
		else if (op == 13)
			ft_putstr("ss\n");
		else if (op == 21)
			ft_putstr("pa\n");
		else if (op == 22)
			ft_putstr("pb\n");
		else if (op == 31)
			ft_putstr("ra\n");
		else if (op == 32)
			ft_putstr("rb\n");
		else if (op == 33)
			ft_putstr("rr\n");
		else if (op == 41)
			ft_putstr("rra\n");
		else if (op == 42)
			ft_putstr("rrb\n");
		else if (op == 43)
			ft_putstr("rrr\n");
//	if (ps->view)
		ft_ps_print_ab(ps);
		ft_printf("============TEST_END==========\n\n\n");
	}
}

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
	if (0 && ps->view)
		ft_ps_print_ab(ps);
}

void			ft_move_n(t_ps *ps, int m)
{
	if (m == 11)
		move_sa(ps);
	else if (m == 12)
		move_sb(ps);
	else if (m == 21)
		move_pa(ps);
	else if (m == 22)
		move_pb(ps);
	else if (m == 31)
		move_ra(ps);
	else if (m == 32)
		move_rb(ps);
	else if (m == 41)
		move_rra(ps);
	else if (m == 42)
		move_rrb(ps);
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
			ft_push_move_test(ps, m);
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
		ft_push_move_test(ps, op);
	}
}

void			move_sa(t_ps *ps)
{
	if (ps->na >= 2)
	{
		ft_dllst_change_ab(ft_dllst_begin(ps->a));
		ps->a = ft_dllst_begin(ps->a);
	}
	if (!(ft_dllst_test(ps->a)))
		ft_printf("ERROR\n");
}

void			move_sb(t_ps *ps)
{
	if (ps->nb >= 2)
	{
		ft_dllst_change_ab(ft_dllst_begin(ps->b));
		ps->b = ft_dllst_begin(ps->b);
	}
	if (!(ft_dllst_test(ps->b)))
		ft_printf("ERROR\n");
}

void			move_ss(t_ps *ps)
{
	move_sa(ps);
	move_sb(ps);
}

void			move_pa(t_ps *ps)
{
	t_dllist	*c;

	if (ps->nb >= 1)
	{
		c = ft_dllst_begin(ps->b);
		ps->b = c->next;
		ft_dllst_pull_out(c);
		ps->nb--;
		ft_dllst_insert_begin(&(ps->a), c);
		ps->a = c;
		ps->na++;
	}
	if (!(ft_dllst_test(ps->a)))
		ft_printf("ERROR\n");
	if (!(ft_dllst_test(ps->b)))
		ft_printf("ERROR\n");
}

void			move_pb(t_ps *ps)
{
	t_dllist	*c;

	if (ps->na >= 1)
	{
		c = ft_dllst_begin(ps->a);
		ps->a = c->next;
		ft_dllst_pull_out(c);
		ps->na--;
		ft_dllst_insert_begin(&(ps->b), c);
		ps->b = c;
		ps->nb++;
	}
	if (!(ft_dllst_test(ps->a)))
		ft_printf("ERROR_pb_a\n");
	if (!(ft_dllst_test(ps->b)))
		ft_printf("ERROR_pb_b\n");
}
