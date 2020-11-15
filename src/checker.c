/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 04:48:53 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/15 04:48:55 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		checker(int argc, char **argv)
{
	t_ps		*ps;

	if (!(ps = init_ps(argc, argv)))
		return (0);

}

int				main(int argc, char **argv)
{
	if (argc == 1)
		return (print_error());
	if (!(checker(argc, argv)))
		return (print_error());
	return (0);
}

