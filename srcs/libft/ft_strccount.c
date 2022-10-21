/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:33:09 by vimatheu          #+#    #+#             */
/*   Updated: 2022/10/20 19:33:42 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strccount(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}
