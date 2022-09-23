#include "../libs/map_generator.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->array[i])
	{
		free(map->array[i]);
		i++;
	}
	free(map->array);
}

void	write_hwall(int fd, size_t size, int final)
{
	while(size > 0)
	{
		write(fd, "1", 1);
		size--;
	}
	if (final == 1)
		write(fd, "\0", 1);
	else
		write(fd, "\n", 1);
}

void	get_random_dir(int *new_dir1, int *new_dir2)
{
	int	random_dir;

	random_dir = random() % 4;
	if (random_dir == 0)
	{
		*new_dir1 = -1;
		*new_dir2 = 0;
	}
	if (random_dir == 1)
	{
		*new_dir1 = 1;
		*new_dir2 = 0;
	}
	if (random_dir == 2)
	{
		*new_dir1 = 0;
		*new_dir2 = -1;
	}
	if (random_dir == 3)
	{
		*new_dir1 = 0;
		*new_dir2 = 1;
	}
}
