/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:25:31 by vimatheu          #+#    #+#             */
/*   Updated: 2022/10/21 22:16:40 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid(t_map *map)
{
	char	*ext;

	ext = ft_substr(map->name, ft_strlen(map->name) - 5, 4);
	if (ft_strncmp(ext, ".ber", 4))
	{
		write(1, "Error\nInvalid file extension.\n", 30);
		free(map->name);
		exit(EXIT_FAILURE);
	}
	if (!ft_strncmp(map->name, "maps/random_map.ber", 19))
		generate_map();
	get_map(map);
	get_player_pos(map);
	is_rectangular(map);
	check_borders(map);
	check_path(map);
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
			free_map(map);
			exit(EXIT_FAILURE);
		}
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
		if (map->array[0][i] != 1 || map->array[map->height - 1][i] != 1)
			is_valid = 0;
		i++;
	}
	i = 1;
	while (i < map->height - 2 && is_valid == 1)
	{
		if (map->array[i][0] != 1 || map->array[i][map->width - 1] != 1)
			is_valid = 0;
		i++;
	}
	if (is_valid == 0)
	{
		write(1, "Error\nMap's borders are not closed.\n", 37);
		free_map(map);
		exit(EXIT_FAILURE);
	}
}

void	check_path(t_map *map)
{
	if (map)
		return ;
}
