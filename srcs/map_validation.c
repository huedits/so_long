/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:25:31 by vimatheu          #+#    #+#             */
/*   Updated: 2022/10/22 19:36:39 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid(t_map *map)
{
	char	*ext;

	ext = ft_substr(map->name, ft_strlen(map->name) - 4, 4);
	if (ft_strncmp(ext, ".ber", 4))
	{
		write(1, "Error\nInvalid file extension.\n", 30);
		free(map->name);
		free(ext);
		exit(EXIT_FAILURE);
	}
	free(ext);
	if (!ft_strncmp(map->name, "maps/random_map.ber", 19))
		generate_map();
	get_map(map);
	is_rectangular(map);
	check_borders(map);
	get_player_pos(map);
	if (check_path(map, map->p_x, map->p_y) > -1)
	{
		write(1, "Error\nMap doesn't have a valid path.\n", 41);
		free_map(map, 1);
		exit(EXIT_FAILURE);
	}
	free_map(map, 0);
	get_map(map);
	print_map_info(map);
}

void	is_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (i < (map->height - 1))
	{
		if (ft_strlen(map->array[i]) != ft_strlen(map->array[i + 1]))
		{
			write(1, "Error\nMap not rectangular.\n", 27);
			free_map(map, 1);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_borders(t_map *map)
{
	int	i;
	int	is_valid;

	print_map_info(map);
	printf("Checking borders...\n");
	i = 0;
	is_valid = 1;
	while (i < map->width && is_valid == 1)
	{
		printf("i = %d | array[0][%d] = %c | array[%d][%d] = %c\n",
			i, i, map->array[0][i], map->height - 1, i, map->array[map->height - 1][i]);
		fflush(stdout);
		if (map->array[0][i] != '1' || map->array[map->height - 1][i] != '1')
			is_valid = 0;
		i++;
	}
	i = 1;
	while (i < map->height - 2 && is_valid == 1)
	{
		printf("array[%d]: %s\n", i, map->array[i]);
		printf("array[%d][0] = %c | array[%d][%d] = %c\n",
			i, map->array[i][0], i, map->width - 1, map->array[i][map->width - 1]);
		fflush(stdout);
		if (map->array[i][0] != '1' || map->array[i][map->width - 1] != '1')
			is_valid = 0;
		i++;
	}
	if (is_valid == 0)
	{
		write(1, "Error\nMap's borders are not closed.\n", 37);
		free_map(map, 1);
		exit(EXIT_FAILURE);
	}
}
