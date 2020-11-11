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

void			move_sa(t_ps *ps)
{
	if (ps->na >= 2)
	{
		ft_dllst_change_ab(ft_dllst_begin(ps->a));
		ps->a = ft_dllst_begin(ps->a);
	}
}

void			move_sb(t_ps *ps)
{
	if (ps->nb >= 2)
	{
		ft_dllst_change_ab(ft_dllst_begin(ps->b));
		ps->b = ft_dllst_begin(ps->b);
	}
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
}
