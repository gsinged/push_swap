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
# include <stdlib.h>

typedef struct		s_dllist
{
	int				n;
	struct s_dllist	*next;
	struct s_dllist	*prev;
}					t_dllist;

typedef struct		s_push_swap
{
	t_dllist		*a;
	t_dllist		*b;
	t_dllist		*nb;
}					t_ps;

t_dllist			*ft_dllst_new(int n);
void				ft_dllst_insert_before(t_dllist *lst, t_dllist *new);
void				ft_dllst_insert_after(t_dllist *lst, t_dllist *new);
void				ft_dllst_insert_begin(t_dllist **lst0, t_dllist *new);
void				ft_dllst_insert_end(t_dllist **lst0, t_dllist *new);
t_dllist			*ft_dllst_begin(t_dllist *cur);
t_dllist			*ft_dllst_end(t_dllist *cur);
void				ft_dllst_delone(t_dllist **one);
void				ft_dllst_delete(t_dllist **lst);
t_dllist			*ft_dllst_copy_one(t_dllist *one);
t_dllist			*ft_dllst_copy(t_dllist *a);
void				ft_dllst_add_sort(t_dllist *a, t_dllist *new);
t_dllist			*ft_dllst_copy_sort(t_dllist *a);

void				ft_ps_del(t_ps **ps);

#endif
