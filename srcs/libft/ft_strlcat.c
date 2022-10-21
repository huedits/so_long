/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:58:08 by vimatheu          #+#    #+#             */
/*   Updated: 2022/08/31 22:18:22 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	total_size;

	if (dstsize > ft_strlen(dst))
	{
		total_size = ft_strlen(dst) + ft_strlen(src);
		while (*dst)
		{
			dst++;
			dstsize--;
		}
		i = 0;
		while (i < (dstsize - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
	{
		total_size = ft_strlen(src) + dstsize;
	}
	return (total_size);
}
