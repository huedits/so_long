#include "../libs/map_generator.h"

void	create_map(void)
{
	t_map	map;

	map.width = (random() % 15) + 7;
	map.height = (random() % 15) + 5;
	map.max_lenght = (map.width + map.height) / 2;
	map.max_tunnels = (map.width + map.height) * 2;
	init_map(&map);
	create_tunnels(&map);
}

int	init_map(t_map *ptmap)
{
	int		i;
	int		j;

	ptmap->array = (char **) malloc ((ptmap->height + 1) * sizeof(char *));
	if (!ptmap->array)
		return (NULL);
	i = 0;
	while (i < height)
	{
		ptmap->array[i] = (char *) malloc (ptmap->width + 1);
		if (!ptmap->array[i])
			return NULL;
		i++;
	}
	ptmap->array[i][0] = 0; //Verificar se é necessário.
	while (i > 0)
	{
		j = 0;
		while (j < width)
		{
			ptmap->array[i - 1][j] = '1';
			j++;
		}
		ptmap->array[i - 1][j] = '\0';
		i++;
	}
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