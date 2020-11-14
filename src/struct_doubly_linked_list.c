/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_doubly_linked_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:24:36 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/09 22:24:37 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_dllist		*ft_dllst_new(int n)
{
	t_dllist	*new;

	if (!(new = (t_dllist*)malloc(sizeof(t_dllist))))
		return (NULL);
	ft_bzero(new, sizeof(t_dllist));
	new->n = n;
	return (new);
}

void			ft_dllst_insert_before(t_dllist *lst, t_dllist *new)
{
	new->next = lst;
	new->prev = lst->prev;
	if (lst->prev)
		lst->prev->next = new;
}

void			ft_dllst_insert_after(t_dllist *lst, t_dllist *new)
{
	new->next = lst->next;
	new->prev = lst;
	lst->next = new;
}

void			ft_dllst_insert_begin(t_dllist **lst0, t_dllist *new)
{
	t_dllist	*lst;

	if (*lst0 && new)
	{
		lst = *lst0;
		while (lst->prev)
			lst = lst->prev;
		ft_dllst_insert_before(lst, new);
	}
	*lst0 = new;
}

void			ft_dllst_insert_end(t_dllist **lst0, t_dllist *new)
{
	t_dllist	*lst;

	if (*lst0 && new)
	{
		lst = *lst0;
		while (lst->next)
			lst = lst->next;
		ft_dllst_insert_after(lst, new);
	}
	else
		*lst0 = new;
}

t_dllist		*ft_dllst_begin(t_dllist *cur)
{
	if (!cur)
		return (NULL);
	while (cur->prev)
		cur = cur->prev;
	return (cur);
}

t_dllist		*ft_dllst_end(t_dllist *cur)
{
	if (!cur)
		return (NULL);
	while (cur->next)
		cur = cur->next;
	return (cur);
}

void			ft_dllst_pull_out(t_dllist *c)
{
	if (c->prev)
		c->prev->next = c->next;
	if (c->next)
		c->next->prev = c->prev;
	c->next = NULL;
	c->prev = NULL;
}

void			ft_dllst_delone(t_dllist **one)
{
	if (one && *one)
	{
		if ((*one)->prev)
			(*one)->prev->next = (*one)->next;
		if ((*one)->next)
			(*one)->next->prev = (*one)->prev;
		ft_bzero(*one, sizeof(t_dllist));
		free(*one);
		*one = NULL;
	}
}

static void		ft_dllst_delete_b(t_dllist **lst)
{
	if (lst && *lst)
	{
		if ((*lst)->next)
			ft_dllst_delete_b(&((*lst)->next));
		ft_bzero(*lst, sizeof(t_dllist));
		free(*lst);
		*lst = NULL;
	}
}

void			ft_dllst_delete(t_dllist **lst)
{
	t_dllist	*c;

	if (lst && *lst)
	{
		if (!(*lst)->prev)
		{
			ft_dllst_delete_b(lst);
		}
		else
		{
			c = ft_dllst_begin(*lst);
			ft_dllst_delete_b(&c);
			*lst = NULL;
		}
	}
}

t_dllist		*ft_dllst_copy_one(t_dllist *one)
{
	t_dllist	*c;

	if (!one)
		return (NULL);
	if (!(c = ft_dllst_new(one->n)))
		return (NULL);
	return (c);
}

t_dllist		*ft_dllst_copy(t_dllist *a)
{
	t_dllist	*begin;
	t_dllist	*cur;
	t_dllist	*c;

	if (!a)
		return (NULL);
	a = ft_dllst_begin(a);
	if (!(begin = ft_dllst_copy_one(a)))
		return (NULL);
	cur = begin;
	a = a->next;
	while (a)
	{
		if (!(c = ft_dllst_copy_one(a)))
		{
			ft_dllst_delete(&begin);
			return (NULL);
		}
		cur->next = c;
		c->prev = cur;
		cur = cur->next;
		a = a->next;
	}
	return (begin);
}

void			ft_dllst_add_sort(t_dllist *a, t_dllist *new)
{
	a = ft_dllst_begin(a);
	while (a->next != NULL)
	{
		if (new->n <= a->n)
			break ;
		a = a->next;
	}
	if (new->n <= a->n)
		ft_dllst_insert_before(a, new);
	else
		ft_dllst_insert_after(a, new);
}

t_dllist		*ft_dllst_copy_sort(t_dllist *a)
{
	t_dllist	*begin;
	t_dllist	*c;

	if (!a)
		return (NULL);
	a = ft_dllst_begin(a);
	if (!(begin = ft_dllst_copy_one(a)))
		return (NULL);
	a = a->next;
	while (a)
	{
		if (!(c = ft_dllst_copy_one(a)))
		{
			ft_dllst_delete(&begin);
			return (NULL);
		}
		ft_dllst_add_sort(begin, c);
		begin = ft_dllst_begin(begin);
		a = a->next;
	}
	return (begin);
}

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
		ft_printf("%5d\n", d->n);
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

int				ft_dllst_position_min(t_dllist *d, t_dllist **lst)
{
	int			i;
	int			min;
	int			p;
	t_dllist	*c;

	d = ft_dllst_begin(d);
	min = d->n;
	c = d;
	p = 1;
	d = d->next;
	i = 2;
	while (d)
	{
		if (d->n < min)
		{
			min = d->n;
			c = d;
			p = i;
		}
		d = d->next;
		i++;
	}
	if (lst)
		*lst = c;
	return (p);
}

t_dllist		*ft_dllst_get_top_n(t_dllist *a, int n)
{
	a = ft_dllst_begin(a);
	while (--n > 0 && a->next)
		a = a->next;
	if (n > 0)
		return (NULL);
	return (a);
}

t_dllist		*ft_dllst_get_bottom_n(t_dllist *a, int n)
{
	a = ft_dllst_end(a);
	while (--n > 0 && a->prev)
		a = a->prev;
	if (n > 0)
		return (NULL);
	return (a);
}

int				ft_dllst_min_n(t_dllist *a)
{
	int		min;

	a = ft_dllst_begin(a);
	min = a->n;
	while (a)
	{
		if (min > a->n)
			min = a->n;
		a = a->next;
	}
	return (min);
}

int				ft_dllst_max_n(t_dllist *a)
{
	int		max;

	a = ft_dllst_begin(a);
	max = a->n;
	while (a)
	{
		if (max < a->n)
			max = a->n;
		a = a->next;
	}
	return (max);
}

int				ft_dllst_medium_n(t_dllist *d)
{
	int			mid;
	int			p;
	int			next;
	t_dllist	*a;
	int			i;

	mid = ft_dllst_lenght(d);
	p = mid / 2;
	mid = ft_dllst_min_n(d);
	i = 1;
	while (p > 0)
	{
		a = ft_dllst_begin(d);
		while (a)
		{
			if (a->n > mid && i)
			{
				next = a->n;
				i = 0;
			}
			if (a->n > mid)
			{
				if (next > a->n)
					next = a->n;
			}
			a = a->next;
		}
		i = 1;
		mid = next;
		p--;
	}
	return (mid);
}

int				ft_dllst_lenght_chunk(t_dllist *d, int ch)
{
	int		i;

	d = ft_dllst_begin(d);
	i = 0;
	while (d)
	{
		if (d->chunk == ch)
			i++;
		d = d->next;
	}
	return (i);
}

int				ft_dllst_min_n_chunk(t_dllist *a, int ch)
{
	int		min;

	a = ft_dllst_begin(a);
	while (a && a->chunk != ch)
		a = a->next;
	min = a->n;
	while (a)
	{
		if (a->chunk == ch && min > a->n)
			min = a->n;
		a = a->next;
	}
	return (min);
}

int				ft_dllst_medium_n_chunk(t_dllist *d, int ch)
{
	int			mid;
	int			p;
	int			next;
	t_dllist	*a;
	int			i;

	mid = ft_dllst_lenght_chunk(d, ch);
	p = mid / 2;
	mid = ft_dllst_min_n_chunk(d, ch);
	i = 1;
	while (p > 0)
	{
		a = ft_dllst_begin(d);
		while (a)
		{
			if (i && a->chunk == ch && a->n > mid)
			{
				next = a->n;
				i = 0;
			}
			if (a->chunk == ch && a->n > mid)
			{
				if (next > a->n)
					next = a->n;
			}
			a = a->next;
		}
		i = 1;
		mid = next;
		p--;
	}
	return (mid);
}

int				ft_dllst_max_chunk(t_dllist *a)
{
	int		ch;

	a = ft_dllst_begin(a);
	ch = a->chunk;
	while (a)
	{
		if (ch < a->chunk)
			ch = a->chunk;
		a = a->next;
	}
	return (ch);
}

int				ft_dllst_max_n_chunk(t_dllist *a, int ch)
{
	int		max;

	a = ft_dllst_begin(a);
	while (a && a->chunk != ch)
		a = a->next;
	max = a->chunk;
	while (a)
	{
		if (a->chunk == ch && max < a->n)
			max = a->n;
		a = a->next;
	}
	return (max);
}


int				ft_dllst_position_max(t_dllist *d, t_dllist **lst)
{
	int			i;
	int			max;
	int			p;
	t_dllist	*c;

	d = ft_dllst_begin(d);
	max = d->n;
	c = d;
	p = 1;
	d = d->next;
	i = 2;
	while (d)
	{
		if (d->n > max)
		{
			max = d->n;
			c = d;
			p = i;
		}
		d = d->next;
		i++;
	}
	if (lst)
		*lst = c;
	return (p);
}

int				ft_dllst_test(t_dllist *a)
{
	a = ft_dllst_begin(a);
	while (a->next)
	{
		if (a->next->prev != a)
			return (0);
	}
	return (1);
}