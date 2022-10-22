/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:39:24 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/01 00:03:28 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size;
	char			*join;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *) ft_calloc (size, sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcat(join, s1, size);
	ft_strlcat(join, s2, size);
	return (join);
}
