/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_step_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:56:58 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/16 11:57:02 by gsinged          ###   ########.fr       */
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

void		ps_step3_sort(t_ps *ps)
{
	int			i;
	t_dllist	*min;

	i = ft_dllst_position_min(ps->a, &min);
	if (i <= (ps->na / 2) + 1)
	{
		while (ps->a != min)
			ft_move(ps, 31);
	}
	else
	{
		while (ps->a != min)
			ft_move(ps, 41);
	}
}

void		ps_step3_two(t_ps *ps)
{
	int		i;

	i = ft_dllst_position_max(ps->a, NULL);
	i = ps->na - i;
	while (i-- > 0)
		ft_move(ps, 41);
	if (ps->a->n > ps->a->next->n)
		ft_move(ps, 11);
}

void		ps_step_3(t_ps *ps)
{
	int		m;
	int		ch;
	int		len;

	ch = ft_dllst_max_chunk(ps->a);
	m = ft_dllst_medium_n_chunk(ps->a, ch);
	len = ft_dllst_lenght_chunk(ps->a, ch);
	while (len > 2)
	{
		ps_step1_chunk(ps, m);
		ch = ft_dllst_max_chunk(ps->a);
		m = ft_dllst_medium_n_chunk(ps->a, ch);
		len = ft_dllst_lenght_chunk(ps->a, ch);
	}
	ps_step3_two(ps);
}
