#include "../libs/map_generator.h"

int	create_map()
{
	t_map	map;
	int		i;
	

	map.width = (random() % 15) + 7;
	map.height = (random() % 15) + 5;
	map.max_lenght = (map.width + map.height) / 2;
	map.max_tunnels = (map.width + map.height) * 2;
	map.array = (char **) malloc ((map.height + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map.array[i] = (char *) malloc (map.width + 1);
		if (!map.array[i])
			return NULL;
		i++;
	}
	map.array[i][0] = 0;
	map.array = init_map(&map);
}

char	**init_map(t_map *ptmap)
{
	int		i;
	int		j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ptmap->array[i][j] = '1';
			j++;
		}
		ptmap->array[i][j] = '\0';
		i++;
	}
	return (array);
}

void	create_tunnels(t_map *tnmap)
{
	int	directions[4][2];
	int	current_pos[2];
	int	last_direction[2];
	int	rand_direction[2];
//					UP		DOWN	LEFT	RIGHT
	directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	last_direction = {2, 2};
	current_pos[0] = random() % height;
	current_pos[1] = random() % width;
	while (tnmap->max_tunnels > 0)
	{
		while((	rand_direction[0] == -last_direction[0] &&    
          		rand_direction[1] == -last_direction[1]) || 
         		(rand_direction[0] == last_direction[0] &&  
          		rand_direction[1] == last_direction[1]))
			rand_direction = directions[random() % 4];
		/*
		WALKING BLOCK
		*/
		tnmap->max_tunnels--;
	}
}