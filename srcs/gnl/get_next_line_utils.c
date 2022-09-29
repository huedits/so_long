/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:01:23 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/29 23:26:25 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c && c[i])
		i++;
	return (i);
}

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

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (size > (~(1 << 31) / count))
		return (NULL);
	mem = malloc (size * count);
	if (mem != NULL)
		ft_bzero(mem, (count * size));
	return (mem);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *) s)[i] = 0;
		i++;
	}
}
