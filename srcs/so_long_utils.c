/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:22:49 by vimatheu          #+#    #+#             */
/*   Updated: 2022/10/21 21:51:21 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->array[i]);
	free(map->array);
	free(map->name);
}

void	generate_map(void)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (access("mapgen", X_OK) == 0)
			execl("mapgen", "mapgen", NULL);
		else
		{
			execl("mapgen", "mapgen", NULL);
		}
	}
	else
		wait(NULL);
}

void	write_array(t_map *map)
{
	char	*mapstr;
	int		i;

	mapstr = read_map(map);
	i = 0;
	while (mapstr[i])
	{
		if (!ft_strchr("10PENC\n", mapstr[i]))
		{
			write(1, "Error\nMap contains invalid element.\n", 36);
			free(map->name);
			free(mapstr);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (ft_strccount(mapstr, 'E') != 1 || ft_strccount(mapstr, 'P') != 1)
		{
			write(1, "Error\nInvalid number of exit/spawn.\n", 36);
			free(map->name);
			free(mapstr);
			exit(EXIT_FAILURE);
		}
	map->coins = ft_strccount(mapstr, 'C');
	map->array = ft_split(mapstr, "\n");
	get_player_pos(map);
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