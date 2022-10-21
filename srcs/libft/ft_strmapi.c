/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:27:08 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/02 17:36:10 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	new_str = (char *) ft_calloc(ft_strlen(s) + 1, 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = (f)(i, s[i]);
		i++;
	}
	return (new_str);
}
