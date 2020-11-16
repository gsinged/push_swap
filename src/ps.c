/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:44:08 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/13 21:44:10 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				print_error(void)
{
	ft_putendl("Error");
	return (0);
}

int			ft_ps(t_ps *ps)
{
	ps_step_1(ps);
	ft_three(ps);
	while (ps->nb > 0)
	{
		ps_step_2(ps);
		ps_step_3(ps);
	}
	return (0);
}
