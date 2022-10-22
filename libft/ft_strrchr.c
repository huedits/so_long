/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 01:51:47 by vimatheu          #+#    #+#             */
/*   Updated: 2022/08/31 20:26:56 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (c > 255)
		return ((char *)s);
	i = 0;
	while (s[i])
		i++;
	while (s[i] != c && i > 0)
		i--;
	if (s[i] == c)
		return ((char *) &s[i]);
	return (NULL);
}
