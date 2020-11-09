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

#endif
