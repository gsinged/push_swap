/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:15:15 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/10 22:15:17 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				print_error(void)
{
	ft_putendl("Error");
	return (0);
}

int				ft_is_int(long long int n)
{
	if (n > 2147483647)
		return (0);
	else if (n < -2147483648)
		return (0);
	return (1);
}

static int		ft_negative_check(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

long long int	ps_atoi(const char *str)
{
	long long int	res;
	int				i;
	int				neg;

	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if ((neg = ft_negative_check(*str)) < 0)
		str++;
	else if (*str == '+')
		str++;
	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		i++;
		str++;
	}
	if (neg < 0)
		res *= neg;
	return (res);
}
