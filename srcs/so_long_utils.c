/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:22:49 by vimatheu          #+#    #+#             */
/*   Updated: 2022/10/22 23:30:48 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map, int all)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->array[i]);
		i++;
	}
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
	char	*aux;

	aux = read_map(map);
	mapstr = ft_strtrim(aux, "\n");
	free(aux);
	map->coins = check_mapstr(map, mapstr);
	map->array = ft_split(mapstr, '\n');
	map->width = ft_strlen(map->array[0]);
	map->height = ft_strccount(mapstr, '\n') + 1;
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
	{
		free(map->name);
		exit_error("Error\nCouldn't read map.\n", map, 0);
	}
	aux = (char *) ft_calloc(1, 1);
	buf = get_next_line(fd);
	while (buf)
	{
		join = ft_strjoin(aux, buf);
		free(aux);
		free(buf);
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
	i = 1;
	while (i < map->height - 1 && found == 0)
	{
		j = 1;
		while (j < map->width - 1 && found == 0)
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
