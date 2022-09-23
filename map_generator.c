#include <time.h>
#include <stdlib.h>

typedef struct	s_map
{
	char	**array;
	size_t	width;
	size_t	height;
	size_t	max_lenght;
	size_t	max_tunnels;
}				t_map;

int	create_map(size_t width, size_t height)
{
	t_map	map;	
	int		i;
	int		current_pos[2];

	if (width < 5 || height < 5)
		return (-1);
	map.width = width - 2;
	map.height = height - 2;
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
	current_pos[0] = random() % height;
	current_pos[1] = random() % width;
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
	int	directions[4][1][2];
	int	last_direction;
	int	rand_direction;

	directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
	tnmap->max_lenght = (tnmap->width * tnmap->height) / 2;
	tnmap->max_tunnels = (tnmap->width * tnmap->height) * 2;
	last_direction = 0;
	while (max_tunnels > 0)
	{
		while(rand_direction == last_direction
			|| rand_direction == 1 && last_direction)
			rand_direction = (random() % 4) + 1;
		walk_tunnel()
	}
}
/* Directions:
	1 - UP 		[-1][0]
	2 - DOWN 	[1]	[0]
	3 - LEFT 	[0]	[-1] 
	4 - RIGHT	[0]	[1]*/

void	get_limits(char ***array, size_t width, size_t height)
{
	int	max_lenght;
	int	max_tunnels;
	int	lowest;

	if (width <= height)
		lowest = width;
	else
		lowest = height;
	srandom(time(NULL));
	max_lenght = (random() % (lowest / 2)) + ((lowest / 2));
	max_tunnels = (random() % lowest) + lowest;
}