/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 05:00:04 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/15 05:00:07 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ch_commands_two(char *line)
{
	if (!(ft_strcmp(line, "sa")))
		return (11);
	else if (!(ft_strcmp(line, "sb")))
		return (12);
	else if (!(ft_strcmp(line, "ss")))
		return (13);
	else if (!(ft_strcmp(line, "pa")))
		return (21);
	else if (!(ft_strcmp(line, "pb")))
		return (22);
	else if (!(ft_strcmp(line, "ra")))
		return (31);
	else if (!(ft_strcmp(line, "rb")))
		return (32);
	else if (!(ft_strcmp(line, "rr")))
		return (33);
	return (0);
}

static int		ch_commands(char *line)
{
	int		len;

	len = ft_strlen(line);
	if (len == 2)
		return (ch_commands_two(line));
	else if (len == 3)
	{
		if (!(ft_strcmp(line, "rra")))
			return (41);
		else if (!(ft_strcmp(line, "rrb")))
			return (42);
		else if (!(ft_strcmp(line, "rrr")))
			return (43);
	}
	return (0);
}

static int		ch_free_line(char **line)
{
	if (line && *line)
	{
		ft_strclr(*line);
		free(*line);
		*line = NULL;
	}
	return (0);
}

int				ch(t_ps *ps)
{
	char	*line;
	int		op;

	while (get_next_line(0, &line))
	{
		if (!(op = ch_commands(line)))
			return (ch_free_line(&line));
		ft_move_n(ps, op);
		ch_free_line(&line);
	}
	ch_free_line(&line);
	if (ft_dllst_q_sort(ps->a) == 1 && !ps->nb)
		return (print_res(1));
	else
		return (print_res(0));
	return (0);
}
