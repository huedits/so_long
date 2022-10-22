/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 22:42:17 by vimatheu          #+#    #+#             */
/*   Updated: 2022/08/31 23:31:51 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	slen;
	unsigned int	size;

	slen = ft_strlen(s);
	if (start >= slen)
		size = 1;
	else if (len >= slen)
		size = (slen - start) + 1;
	else
		size = len + 1;
	sub = malloc (size);
	if (!sub)
		return (NULL);
	i = 0;
	while (((start + i) < slen) && (i < len))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
