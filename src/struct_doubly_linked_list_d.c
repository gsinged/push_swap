
#include "push_swap.h"

int				ft_dllst_lenght(t_dllist *d)
{
	int		i;

	d = ft_dllst_begin(d);
	i = 0;
	while (d)
	{
		i++;
		d = d->next;
	}
	return (i);
}

void			ft_dllst_print(t_dllist *d)
{
	d = ft_dllst_begin(d);
	while (d)
	{
		ft_printf("%d\n", d->n);
		d = d->next;
	}
}

void			ft_dllst_change_ab(t_dllist *a)
{
	t_dllist	*c;

	if (a && a->next)
	{
		c = a->next;
		a->next = c->next;
		if (c->next)
			c->next->prev = a;
		c->next = a;
		if (a->prev)
			a->prev->next = c;
		c->prev = a->prev;
		a->prev = c;
	}
}

static int		ft_dllst_q_sort_x(t_dllist *x)
{
	t_dllist	*c;
	t_dllist	*begin;

	c = x;
	while (c->next)
	{
		if (c->n > c->next->n)
			return (0);
		c = c->next;
	}
	begin = ft_dllst_begin(x);
	if (c->n > begin->n)
		return (0);
	while (begin->next != x)
	{
		if (begin->n > begin->next->n)
			return (0);
		begin = begin->next;
	}
	return (2);
}

int				ft_dllst_q_sort(t_dllist *a)
{
	a = ft_dllst_begin(a);
	while (a->next)
	{
		if (a->n > a->next->n)
			return (ft_dllst_q_sort_x(a->next));
		a = a->next;
	}
	return (1);
}
