/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:22:49 by vimatheu          #+#    #+#             */
/*   Updated: 2022/10/22 18:50:04 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map, int all)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->array[i]);
	free(map->array);
	if (all == 1)
		free(map->name);
}

void	generate_map(void)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		execlp("make", "make", "regen", NULL);
	else
		wait(NULL);
}

void	get_map(t_map *map)
{
	char	*mapstr;

	mapstr = read_map(map);
	map->coins = check_mapstr(map, mapstr);
	map->array = ft_split(mapstr, '\n');
	free(mapstr);
}

char	*read_map(t_map	*map)
{
	int		fd;
	char	*buf;
	char	*aux;
	char	*join;

	fd = open(map->name, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	aux = (char *) ft_calloc(1, 1);
	buf = get_next_line(fd);
	map->width = ft_strlen(buf) - 1;
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

void	get_player_pos(t_map *map)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = 0;
	while (i < map->height && found == 0)
	{
		j = 0;
		while (j < map->width && found == 0)
		{
			if (map->array[i][j] == 'P')
			{
				map->p_x = j;
				map->p_y = i;
				found = 1;
			}
			j++;
		}
		i++;
	}
}
