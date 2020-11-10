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

t_ps		*init_ps(t_dllist *a)
{
	t_ps		*ps;
	t_dllist	*c;

	if (!(ps = (t_ps *)malloc(sizeof(t_ps))))
	{
		ft_dllst_delete(&a);
		return (NULL);
	}
	ft_bzero(ps, sizeof(t_ps));
	ps->a = a;
	if (!(c = ft_dllst_copy(a)))
	{
		ft_ps_del(&ps);
		return (NULL);
	}
	ps->nb = c;
	return (ps);
}

int			cmp_val_stack_a(t_dllist *a, int n)
{
	if (!a)
		return (0);
	a = ft_dllst_begin(a);
	while (a)
	{
		if (a->n == n)
			return (0);
		a = a->next;
	}
	return (1);
}

t_dllist	*init_stack_a(int argc, char **argv)
{
	int			i;
	t_dllist	*a;
	t_dllist	*c;
	int			n;

	i = 1;
	a = NULL;
	while (i <= argc)
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
		ft_dllst_insert_end(&a, c);
		i++;
	}
	return (a);
}

int			push_swap(t_dllist *a)
{
	t_ps		*ps;

	return (0);
}

int			main(int argc, char **argv)
{
	t_dllist	*a;

	if (argc == 1)
		return (print_ko());
	if (!(a = init_stack_a(argc, argv)))
		return (print_ko());
	return (0);
}
