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

void	get_random_dir(int *new_dir)
{
	int	random_dir;

	random_dir = random() % 4;
	if (random_dir == 0)
	{
		*new_dir[0] = -1;
		*new_dir[1] = 0;
	}
	if (random_dir == 1)
	{
		*new_dir[0] = 1;
		*new_dir[1] = 0;
	}
	if (random_dir == 2)
	{
		*new_dir[0] = 0;
		*new_dir[1] = -1;
	}
	if (random_dir == 3)
	{
		*new_dir[0] = 0;
		*new_dir[1] = 1;
	}
}