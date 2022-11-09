/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:20:01 by vimatheu          #+#    #+#             */
/*   Updated: 2022/11/09 19:23:40 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_mapstr(t_map *map, char *str)
{
	int	i;
	int	coins;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("10PENC\n", str[i]))
		{
			free(str);
			free(map->name);
			exit_error("Error\nMap contains invalid element.\n", map, 0);
		}
		i++;
	}
	coins = ft_strccount(str, 'C');
	if (ft_strccount(str, 'E') != 1 || ft_strccount(str, 'P') != 1
		|| coins < 1)
	{
		free(map->name);
		free(str);
		exit_error("Error\nInvalid number of exit/spawn/collectibles.\n", map, 0);
	}
	return (coins);
}

int	get_next_path(t_map *mp, int x, int y)
{
	if (mp->array[y][x] != '1' && mp->array[y][x] != 'X'
		&& mp->array[y][x] != 'N')
		return (1);
	return (0);
}

int	check_path(t_map *map, int x, int y)
{
	if (map->array[y][x] == 'C' || map->array[y][x] == 'E')
		map->coins--;
	map->array[y][x] = 'X';
	if (get_next_path(map, x, y - 1) && map->coins > -1)
		check_path(map, x, y - 1);
	if (get_next_path(map, x, y + 1) && map->coins > -1)
		check_path(map, x, y + 1);
	if (get_next_path(map, x - 1, y) && map->coins > -1)
		check_path(map, x - 1, y);
	if (get_next_path(map, x + 1, y) && map->coins > -1)
		check_path(map, x + 1, y);
	return (map->coins);
}

void	exit_error(char *str, t_map *map, int nf)
{
	write(1, str, ft_strlen(str));
	if (nf == 1)
		free_map(map, 1);
	exit(EXIT_FAILURE);
}
