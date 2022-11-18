/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:25:31 by vimatheu          #+#    #+#             */
/*   Updated: 2022/11/18 22:55:20 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid(t_map *map)
{
	char	*ext;

	if (ft_strlen(map->name) <= 4)
	{
		free(map->name);
		exit_error("Error\nInvalid file extension.\n", map, 0);
	}
	ext = ft_substr(map->name, ft_strlen(map->name) - 5, 5);
	if (ft_strncmp(ext + 1, ".ber", 4) || !ft_strncmp(ext, "/.ber", 5))
	{
		free(map->name);
		free(ext);
		exit_error("Error\nInvalid file extension.\n", map, 0);
	}
	free(ext);
	if (!ft_strncmp(map->name, "maps/random_map.ber", 19))
		generate_map();
	get_map(map);
	is_rectangular(map);
	check_borders(map);
	get_player_pos(map);
	if (check_path(map, map->p_x, map->p_y) > -1)
		exit_error("Error\nMap doesn't have a valid path.\n", map, 1);
	free_map(map, 0);
	get_map(map);
}

void	is_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (i < (map->height - 1))
	{
		if (ft_strlen(map->array[i]) != ft_strlen(map->array[i + 1]))
			exit_error("Error\nMap not rectangular.\n", map, 1);
		i++;
	}
}

void	check_borders(t_map *map)
{
	int	i;
	int	is_valid;

	i = 0;
	is_valid = 1;
	while (i < map->width && is_valid == 1)
	{
		if (map->array[0][i] != '1' || map->array[map->height - 1][i] != '1')
			is_valid = 0;
		i++;
	}
	i = 1;
	while (i < map->height - 1 && is_valid == 1)
	{
		if (map->array[i][0] != '1' || map->array[i][map->width - 1] != '1')
			is_valid = 0;
		i++;
	}
	if (is_valid == 0)
		exit_error("Error\nMap's borders are not closed.\n", map, 1);
}
