/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:05:58 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/29 01:51:22 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/map_generator.h"

void	create_map(void)
{
	t_map	map;

	srandom(time(NULL));
	map.width = (random() % 16) + 7;
	map.height = (random() % 16) + 5;
	map.max_lenght = (map.width + map.height) / 2;
	map.max_tunnels = map.max_lenght * 4;
	map.collectibles = (random() % 9) + 3;
	init_map(&map);
	create_tunnels(&map);
	add_collectibles(&map);
	write_map(&map);
	free_map(&map, map.height);
}

void	init_map(t_map *ptmap)
{
	int		i;
	int		j;

	ptmap->array = (char **) malloc ((ptmap->height + 1) * sizeof(char *));
	if (!ptmap->array)
		return ;
	i = 0;
	while (i < ptmap->height)
	{
		ptmap->array[i] = (char *) malloc (ptmap->width + 1);
		if (!ptmap->array[i])
			return ;
		i++;
	}
	while (i > 0)
	{
		j = 0;
		while (j < ptmap->width)
		{
			ptmap->array[i - 1][j] = '1';
			j++;
		}
		ptmap->array[i - 1][j] = '\0';
		i--;
	}
}

void	create_tunnels(t_map *tnmap)
{
	int	cpos[2];
	int	ldir[2];
	int	rdir[2];

	ldir[0] = 0;
	ldir[1] = 0;
	cpos[0] = random() % tnmap->height;
	cpos[1] = random() % tnmap->width;
	tnmap->array[cpos[0]][cpos[1]] = 'P';
	while (tnmap->max_tunnels > 0)
	{
		get_random_dir(&rdir[0]);
		while ((rdir[0] == -ldir[0] && rdir[1] == -ldir[1])
			|| (rdir[0] == ldir[0] && rdir[1] == ldir[1]))
			get_random_dir(&rdir[0]);
		new_tunnel(tnmap, rdir, cpos);
		ldir[0] = rdir[0];
		ldir[1] = rdir[1];
		tnmap->max_tunnels--;
	}
	if (tnmap->array[cpos[0]][cpos[1]] == '1'
		|| tnmap->array[cpos[0]][cpos[1]] == '0')
		tnmap->array[cpos[0]][cpos[1]] = 'E';
}

void	add_collectibles(t_map *map)
{
	int		rpos[2];
	int	col_added;

	col_added = 0;
	while (col_added <= map->collectibles)
	{
		rpos[0] = random() % map->height;
		rpos[1] = random() % map->width;
		if (map->array[rpos[0]][rpos[1]] == '0')
		{
			map->array[rpos[0]][rpos[1]] = 'C';
			col_added++;
		}
	}
}

void	write_map(t_map *map)
{
	int	fd;
	int	i;
	int	j;

	remove("map");
	fd = open("map", O_RDWR | O_CREAT, 0666);
	write_hwall(fd, (map->width + 2), 0);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		write(fd, "1", 1);
		while (j < map->width)
		{
			write(fd, &(map->array[i][j]), 1);
			j++;
		}
		write(fd, "1\n", 2);
		i++;
	}
	write_hwall(fd, (map->width + 2), 1);
	close(fd);
}
