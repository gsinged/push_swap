/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:03:07 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/10 19:03:08 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_ps_del(t_ps **ps)
{
	if (ps && *ps)
	{
		ft_dllst_delete(&((*ps)->a));
		ft_dllst_delete(&((*ps)->b));
		ft_dllst_delete(&((*ps)->nb));
		ft_bzero(*ps, sizeof(t_ps));
		free(*ps);
		*ps = NULL;
	}
}

void		ft_ps_print_ab(t_ps *ps)
{
	int			len_a;
	int			len_b;
	t_dllist	*a;
	t_dllist	*b;

	len_a = ft_dllst_lenght(ps->a);
	len_b = ft_dllst_lenght(ps->b);
	a = ps->a;
	b = ps->b;
}