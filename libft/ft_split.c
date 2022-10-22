/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:25:29 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/02 17:19:28 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char delim);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	size;
	char	**tab;

	tab = (char **) ft_calloc (count_words(s, c) + 1, sizeof(char *));
	if (!tab || !s)
		return (NULL);
	i = 0;
	size = 0;
	while (*s)
	{
		if (*s != c)
			size++;
		if (*s == c && size > 0)
		{
			tab[i] = ft_substr((s - size), 0, size);
			i++;
			size = 0;
		}
		s++;
	}
	if (size > 0)
		tab[i] = ft_substr((s - size), 0, size);
	return (tab);
}

static int	count_words(char const *str, char delim)
{
	int	count;
	int	new;

	count = 0;
	new = 1;
	while (*str)
	{
		if (*str != delim && new == 1)
		{
			count++;
			new = 0;
		}
		if (*str == delim)
			new = 1;
		str++;
	}
	return (count);
}
