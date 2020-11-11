/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:02:38 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/11 14:02:41 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			cmp_val_stack_a(t_dllist *a, int n)
{
	if (!a)
		return (1);
	a = ft_dllst_begin(a);
	while (a)
	{
		if (a->n == n)
			return (0);
		a = a->next;
	}
	return (1);
}

static int			ft_size_nbr(int n)
{
	int			s;
	long int	c;

	s = 0;
	c = n;
	if (c == 0)
		return (1);
	else if (c < 0)
	{
		c *= -1;
		s++;
	}
	while (c)
	{
		c /= 10;
		s++;
	}
	return (s);
}

static t_dllist		*init_stack_a(int argc, char **argv, int *size, int i)
{
	t_dllist	*a;
	t_dllist	*c;
	int			n;

	a = NULL;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (!(c = ft_dllst_new(n)))
		{
			ft_dllst_delete(&a);
			return (NULL);
		}
		if (!(cmp_val_stack_a(a, n)))
		{
			ft_dllst_delete(&a);
			return (NULL);
		}
		n = ft_size_nbr(n);
		*size < n ? *size = n : 0;
		ft_dllst_insert_end(&a, c);
		i++;
	}
	return (a);
}

t_ps				*init_ps(int argc, char **argv)
{
	t_dllist	*a;
	t_ps		*ps;
	t_dllist	*c;
	int			size;

	size = 0;
	if (!(ps = (t_ps *)malloc(sizeof(t_ps))))
		return (NULL);
	ft_bzero(ps, sizeof(t_ps));
	if (!(a = init_stack_a(argc, argv, &size, 1)))
		return (ft_ps_del_null(&ps));
	ps->a = a;
	ps->size = size;
	if (!(c = ft_dllst_copy(a)))
		return (ft_ps_del_null(&ps));
	ps->sort = c;
	ps->len = ft_dllst_lenght(ps->a);
	ps->na = ps->len;
	ps->nb = 0;
	ft_ps_print_ab(ps);
	return (ps);
}
