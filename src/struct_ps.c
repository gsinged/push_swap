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
		ft_dllst_delete(&((*ps)->sort));
		ft_bzero(*ps, sizeof(t_ps));
		free(*ps);
		*ps = NULL;
	}
}

t_ps		*ft_ps_del_null(t_ps **ps)
{
	ft_ps_del(ps);
	return (NULL);
}

static void	print_ab(int p, t_dllist **d, t_ps *ps)
{
	t_dllist *cur;

	cur = *d;
	while (p > 0)
	{
		ft_printf("%*d\t%*c\n", ps->size, cur->n, ps->size, ' ');
		cur = cur->next;
		p--;
	}
	while (p < 0)
	{
		ft_printf("%*c\t%*d %d\n", ps->size, ' ', ps->size, cur->n, cur->chunk);
		cur = cur->next;
		p++;
	}
	*d = cur;
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
	print_ab(len_a - len_b, (len_a - len_b) > 0 ? &a : &b, ps);
	while (a && b)
	{
		ft_printf("%*d\t%*d %d\n", ps->size, a->n, ps->size, b->n, b->chunk);
		a = a->next;
		b = b->next;
	}
	ft_printf("%*c\t%*c\n", ps->size, '-', ps->size, '-');
	ft_printf("%*c\t%*c\n", ps->size, 'a', ps->size, 'b');
	ft_putstr("----------\n\n");
}
