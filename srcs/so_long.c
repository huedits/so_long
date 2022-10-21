/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:05:57 by vimatheu          #+#    #+#             */
/*   Updated: 2022/10/21 02:33:34 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int		id;
	t_game	game;

	id = fork();
	if (id == 0)
		generate_map();
	else
	{
		wait(NULL);
		write_array(&game.map);
	}
}

void	generate_map(void)
{
	int	pid;

	if (access("mapgen", X_OK) == 0)
		execl("mapgen", "mapgen", NULL);
	else
	{
		pid = fork();
		if (pid == 0)
			execlp("make", "make", "regen", NULL);
		else
		{
			wait(NULL);
			execl("mapgen", "mapgen", NULL);
		}
	}
}

char	*read_map(t_map	*map)
{
	int		fd;
	char	*buf;
	char	*aux;
	char	*join;

	fd = open("map", O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	aux = (char *) ft_calloc (1,1);
	buf = get_next_line(fd);
	map->width = ft_strlen(buf);
	map->height = 0;
	while (buf)
	{
		join = ft_strjoin(aux, buf);
		free(aux);
		free(buf);
		map->height++;
		buf = get_next_line(fd);
		aux = join;
	}
	close(fd);
	free(buf);
	return (join);
}

void	write_array(t_map *map)
{
	char	*mapstr;
	int		i;
	int		j;

	mapstr = read_map(map);
	map->coins = ft_strccount(mapstr, 'C');
	map->array = (char **) malloc (map->height * sizeof(char *));
	i = 0;
	while (i < map->height)
	{
		map->array[i] = (char *) malloc (map->width);
		j = 0;
		while (j < map->width - 1)
		{
			map->array[i][j] = *mapstr;
			mapstr++;
			j++;
		}
		if (*mapstr == '\n')
			mapstr++;
		map->array[i][j] = 0;
		i++;
	}
}
