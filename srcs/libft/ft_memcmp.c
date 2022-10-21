/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:21:09 by vimatheu          #+#    #+#             */
/*   Updated: 2022/08/31 19:32:16 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char *) s1;
	str2 = (char *) s2;
	i = 0;
	while (str1[i] == str2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	else
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
