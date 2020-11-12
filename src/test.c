/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:15:15 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/10 22:15:17 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int			ft_three(t_ps *ps)
{
	while (!ft_dllst_q_sort(ps->a))
	{
		move_sa(ps);
		ft_printf("sa\n");
		ft_ps_print_ab(ps);
	}
	if (ft_dllst_q_sort(ps->a) == 1)
		return (1);
	else
	{
		if (ft_dllst_position_min(ps->a, NULL) == 2)
		{
			move_ra(ps);
			ft_printf("ra\n");
			ft_ps_print_ab(ps);
		}
		else
		{
			move_rra(ps);
			ft_printf("rra\n");
			ft_ps_print_ab(ps);
		}
	}
	if (ft_dllst_q_sort(ps->a) == 1)
		return (1);
	else
		ft_printf("KKKKKOOOOO\n");
	return (0);
}