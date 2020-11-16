/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:45:19 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/09 21:45:21 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ps_viewer(char **argv)
{
	if (*argv[1] == '-' && argv[1][1] == 'v' && !argv[1][2])
		return (1);
	return (0);
}

static int		push_swap(int argc, char **argv, int viewer)
{
	t_ps		*ps;

	if (!(ps = init_ps(argc, argv)))
		return (0);
	if ((ps->view = viewer))
	{
		ft_putstr("init\n");
		ft_ps_print_ab(ps);
	}
	if (ps->len <= 3)
		ft_three(ps);
	else
		ft_ps(ps);
	if (ps->last)
		ft_push_move(ps);
	ft_ps_del(&ps);
	return (1);
}

int				main(int argc, char **argv)
{
	int		viewer;

	if (argc == 1)
		return (print_error());
	if ((viewer = ps_viewer(argv)))
	{
		argc--;
		argv++;
	}
	if (!(push_swap(argc, argv, viewer)))
		return (print_error());
	return (0);
}
