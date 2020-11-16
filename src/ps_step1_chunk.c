
#include "push_swap.h"

void		ps_step1_f(t_ps *ps)
{
	t_dllist	*end;

	end = ft_dllst_end(ps->a);
	if (ps->a->n > ps->a->next->n)
	{
		ft_move(ps, 11);
	}
	while (ps->a->n > end->n)
	{
		ft_move(ps, 41);
		end = ft_dllst_end(ps->a);
	}
	ps->a = ft_dllst_begin(ps->a);
}

int			ps_step1_top(t_ps *ps, int m)
{
	ps->a = ft_dllst_begin(ps->a);
	if (ps->a->n >= m)
		return (0);
	ps_step1_f(ps);
	ps->a->chunk = ps->chunk;
	ft_move(ps, 22);
	return (1);
}

int			ps_step1_bottom(t_ps *ps, int m)
{
	t_dllist	*end;

	end = ft_dllst_end(ps->a);
	ps->a = ft_dllst_begin(ps->a);
	if (end->n >= m)
		return (0);
	ft_move(ps, 41);
	return (1);
}

int			ps_step1_sec_end(t_ps *ps, int m)
{
	t_dllist	*end;

	ps->a = ft_dllst_begin(ps->a);
	end = ft_dllst_end(ps->a);
	if (ps->a->next->n < m && ps->a->next->n < end->n)
		ft_move(ps, 31);
	else
		return (0);
	return (ps_step1_top(ps, m));
}


void		ps_step1_chunk(t_ps *ps, int m)
{
	int		i;

	ps->chunk++;
	i = 1;
	while (i)
	{
		if (ft_dllst_q_sort(ps->a))
		{
			ps_step3_sort(ps);
			i = 0;
		}
		if (ps_step1_top(ps, m))
			i = 1;
		else if ((ps_step1_sec_end(ps, m)))
			i = 1;
		else if (ps_step1_bottom(ps, m))
			i = 1;
		else if (ps_step1_ra_rra(ps, m))
			i = 1;
		else
			i = 0;
	}
}
