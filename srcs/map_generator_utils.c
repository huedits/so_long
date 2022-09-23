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