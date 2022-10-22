/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:45:04 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/06 06:03:04 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_limit(int res, int next, int sign);

int	ft_atoi(const char *c)
{
	int				res;
	int				sig;

	res = 0;
	sig = 1;
	while (*c == ' ' || (*c >= 8 && *c <= 14))
		c++;
	if (*c == '+' || *c == '-')
	{
		if (*c == '-')
			sig *= -1;
		c++;
	}
	while (ft_isdigit(*c))
	{
		if (!check_limit(res, *c - '0', sig))
			return (0);
		res = res * 10 + (*c - '0');
		c++;
	}
	return (res * sig);
}

static int	check_limit(int res, int next, int sign)
{
	if (sign < 0)
	{
		if (-res < ((1 << 31) + next) / 10)
			return (0);
	}
	else
	{
		if (res > (~(1 << 31) - next) / 10)
			return (0);
	}
	return (1);
}
