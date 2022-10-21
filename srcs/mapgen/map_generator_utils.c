/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:06:00 by vimatheu          #+#    #+#             */
/*   Updated: 2022/10/21 03:15:54 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_generator.h"

void	free_map(t_map *map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map->array[i]);
		i++;
	}
	free(map->array);
}

void	write_hwall(int fd, int size, int final)
{
	while (size > 0)
	{
		write(fd, "1", 1);
		size--;
	}
	if (final != 1)
		write(fd, "\n", 1);
}

void	get_random_dir(int *new_dir, int *last_dir)
{
	int	random_dir;

	random_dir = random() % 4;
	if (random_dir == 0)
		new_dir[0] = -1;
	else if (random_dir == 1)
		new_dir[0] = 1;
	else if (random_dir == 2)
		new_dir[0] = 0;
	else if (random_dir == 3)
		new_dir[0] = 0;
	if (random_dir == 0)
		new_dir[1] = 0;
	else if (random_dir == 1)
		new_dir[1] = 0;
	else if (random_dir == 2)
		new_dir[1] = -1;
	else if (random_dir == 3)
		new_dir[1] = 1;
	if ((new_dir[0] == -last_dir[0] && new_dir[1] == -last_dir[1])
		|| (new_dir[0] == last_dir[0] && new_dir[1] == last_dir[1]))
		get_random_dir(new_dir, last_dir);
}

void	new_tunnel(t_map *map, int *rdir, int *cpos)
{
	int	tunnel_size;

	tunnel_size = (random() % map->max_lenght) + 1;
	while (tunnel_size > 0)
	{
		if ((rdir[0] == -1 && cpos[0] == 0)
			|| (rdir[0] == 1 && cpos[0] == map->height - 1)
			|| (rdir[1] == -1 && cpos[1] == 0)
			|| (rdir[1] == 1 && cpos[1] == map->width - 1))
			break ;
		cpos[0] += rdir[0];
		cpos[1] += rdir[1];
		if (map->array[cpos[0]][cpos[1]] == '1')
			map->array[cpos[0]][cpos[1]] = '0';
		tunnel_size--;
	}
}
