/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:20:01 by vimatheu          #+#    #+#             */
/*   Updated: 2022/10/22 18:44:03 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_mapstr(t_map *map, char *str)
{
	int	i;
	int	coins;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("10PENC\n", str[i]))
		{
			write(1, "Error\nMap contains invalid element.\n", 36);
			free(map->name);
			free(str);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	coins = ft_strccount(str, 'C');
	if (ft_strccount(str, 'E') != 1 || ft_strccount(str, 'P') != 1
		|| coins < 1)
	{
		write(1, "Error\nInvalid number of exit/spawn/collectibles.\n", 49);
		free(map->name);
		free(str);
		exit(EXIT_FAILURE);
	}
	return (coins);
}

int		get_next_path(t_map *mp, int y, int x)
{
	if (mp->array[y][x] != '1' && mp->array[y][x] != 'X'
		&& mp->array[y][x] != 'N')
		return (1);
	return (0);
}

int		check_path(t_map *map, int x, int y)
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

void	print_map_info(t_map *map)
{
	int i, j;
	
	printf("map->name: %s\n", map->name);
	printf("Width: %d | Height: %d | Coins: %d\n\nArray:\n", map->width, map->height, map->coins);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%c", map->array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\nP: [%d][%d]\n", map->p_y, map->p_x);
}