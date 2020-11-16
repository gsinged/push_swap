
#include "push_swap.h"

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
