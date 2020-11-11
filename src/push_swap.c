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

int			print_ko(void)
{
	ft_putendl("KO");
	return (0);
}

int			push_swap(int argc, char **argv)
{
	t_ps		*ps;

	if (!(ps = init_ps(argc, argv)))
		return (0);
	ft_ps_del(&ps);
	return (1);
}

int			main(int argc, char **argv)
{
	if (argc == 1)
		return (print_ko());
	if (!(push_swap(argc, argv)))
		return (print_ko());
	return (0);
}
