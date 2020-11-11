/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:02:34 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/11 20:02:36 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			move_rra(t_ps *ps)
{
	t_dllist	*c;

	if (ps->na >= 2)
	{
		c = ft_dllst_end(ps->a);
		ft_dllst_pull_out(c);
		ft_dllst_insert_begin(&(ps->a), c);
		ps->a = c;
	}
}

void			move_rrb(t_ps *ps)
{
	t_dllist	*c;

	if (ps->nb >= 2)
	{
		c = ft_dllst_end(ps->b);
		ft_dllst_pull_out(c);
		ft_dllst_insert_begin(&(ps->b), c);
		ps->b = c;
	}
}

void			move_rrr(t_ps *ps)
{
	move_rra(ps);
	move_rrb(ps);
}
