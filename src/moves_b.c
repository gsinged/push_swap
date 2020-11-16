/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:02:12 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/11 20:02:14 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			move_ra(t_ps *ps)
{
	t_dllist	*c;

	if (ps->na >= 2)
	{
		c = ft_dllst_begin(ps->a);
		ps->a = c->next;
		ft_dllst_pull_out(c);
		ft_dllst_insert_end(&(ps->a), c);
	}
}

void			move_rb(t_ps *ps)
{
	t_dllist	*c;

	if (ps->nb >= 2)
	{
		c = ft_dllst_begin(ps->b);
		ps->b = c->next;
		ft_dllst_pull_out(c);
		ft_dllst_insert_end(&(ps->b), c);
	}
}

void			move_rr(t_ps *ps)
{
	move_ra(ps);
	move_rb(ps);
}
