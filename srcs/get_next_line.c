/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:01:41 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/13 11:33:06 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*aux;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = aux;
	if (!aux)
		aux = (char *) ft_calloc(1, 1);
	if (read_file(&aux, &line, fd))
		return (line);
	if (!*aux)
	{
		free(aux);
		aux = NULL;
		return (NULL);
	}
	line = aux;
	aux = NULL;
	return (line);
}

int	read_file(char **aux_p, char **line_p, int fd)
{
	char		*buffer;
	ssize_t		i;
	ssize_t		chars_read;

	i = 0;
	chars_read = BUFFER_SIZE;
	while (chars_read > 0)
	{
		while ((*aux_p)[i] != '\n' && (*aux_p)[i])
			i++;
		if ((*aux_p)[i] == '\n')
		{
			*line_p = *aux_p;
			*aux_p = ft_substr(*line_p, i + 1, ft_strlen(*line_p + i + 1));
			ft_bzero(*line_p + i + 1, ft_strlen(*line_p + i + 1));
			return (1);
		}
		buffer = (char *) ft_calloc(BUFFER_SIZE + 1, 1);
		chars_read = read(fd, buffer, BUFFER_SIZE);
		*line_p = ft_strjoin(*aux_p, buffer);
		free(*aux_p);
		*aux_p = *line_p;
		free(buffer);
	}
	return (0);
}

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
		while (i < (dstsize - 1) && src && src[i])
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

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	dup = malloc ((ft_strlen(s1) + 1) * sizeof (char));
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
