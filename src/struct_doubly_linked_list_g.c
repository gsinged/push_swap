
#include "push_swap.h"

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

int				ft_dllst_test(t_dllist *a)
{
	if (!a)
		return (1);
	a = ft_dllst_begin(a);
	while (a->next)
	{
		if (a->next->prev != a)
			return (0);
		a = a->next;
	}
	return (1);
}
