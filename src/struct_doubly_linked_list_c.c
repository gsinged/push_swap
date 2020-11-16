
#include "push_swap.h"

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
