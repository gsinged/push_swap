/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:54:50 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/09 21:54:52 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "libftprintf.h"
# include <stdlib.h>

typedef struct		s_dllist
{
	int				n;
	int				chunk;
	struct s_dllist	*next;
	struct s_dllist	*prev;
}					t_dllist;

typedef struct		s_push_swap
{
	t_dllist		*a;
	t_dllist		*b;
	t_dllist		*sort;
	int				na;
	int				nb;
	int				len;
	int				size;
	int				last;
	int				view;
	int				chunk;
}					t_ps;

t_dllist			*ft_dllst_new(int n);
void				ft_dllst_insert_before(t_dllist *lst, t_dllist *new);
void				ft_dllst_insert_after(t_dllist *lst, t_dllist *new);
void				ft_dllst_insert_begin(t_dllist **lst0, t_dllist *new);
void				ft_dllst_insert_end(t_dllist **lst0, t_dllist *new);
t_dllist			*ft_dllst_begin(t_dllist *cur);
t_dllist			*ft_dllst_end(t_dllist *cur);
void				ft_dllst_pull_out(t_dllist *c);
void				ft_dllst_delone(t_dllist **one);
void				ft_dllst_delete(t_dllist **lst);
t_dllist			*ft_dllst_copy_one(t_dllist *one);
t_dllist			*ft_dllst_copy(t_dllist *a);
void				ft_dllst_add_sort(t_dllist *a, t_dllist *new);
t_dllist			*ft_dllst_copy_sort(t_dllist *a);
int					ft_dllst_lenght(t_dllist *d);
void				ft_dllst_print(t_dllist *d);
void				ft_dllst_change_ab(t_dllist *a);
int					ft_dllst_q_sort(t_dllist *a);
int					ft_dllst_position_min(t_dllist *d, t_dllist	**lst);
t_dllist			*ft_dllst_get_top_n(t_dllist *a, int n);
t_dllist			*ft_dllst_get_bottom_n(t_dllist *a, int n);
int					ft_dllst_medium_n(t_dllist *a);
int					ft_dllst_medium_n_chunk(t_dllist *d, int ch);
int					ft_dllst_max_chunk(t_dllist *a);
int					ft_dllst_lenght_chunk(t_dllist *d, int ch);

t_ps				*init_ps(int argc, char **argv);
void				ft_ps_del(t_ps **ps);
t_ps				*ft_ps_del_null(t_ps **ps);

void				ft_ps_print_ab(t_ps *ps);

void				ft_move(t_ps *ps, int op);
void				ft_push_move(t_ps *ps);

void				move_sa(t_ps *ps);
void				move_sb(t_ps *ps);
void				move_ss(t_ps *ps);
void				move_pa(t_ps *ps);
void				move_pb(t_ps *ps);
void				move_ra(t_ps *ps);
void				move_rb(t_ps *ps);
void				move_rr(t_ps *ps);
void				move_rra(t_ps *ps);
void				move_rrb(t_ps *ps);
void				move_rrr(t_ps *ps);

int					ft_ps(t_ps *ps);
int					ft_three(t_ps *ps);
void				ps_step_1(t_ps *ps);
void				ps_step_2(t_ps *ps);

#endif
