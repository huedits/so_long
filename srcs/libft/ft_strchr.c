/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:01:52 by vimatheu          #+#    #+#             */
/*   Updated: 2022/08/31 20:21:06 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (c > 255)
		return (str);
	while (*str && *str != c)
		str++;
	if (*str == c)
		return (str);
	return (NULL);
}
