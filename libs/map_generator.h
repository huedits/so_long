#ifndef MAP_GENERATOR_H
# define MAP_GENERATOR_H

# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
//						UP		DOWN	LEFT	RIGHT
# define DIRECTIONS {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

typedef struct	s_map
{
	char	**array;
	size_t	width;
	size_t	height;
	size_t	max_lenght;
	size_t	max_tunnels;
	size_t	collectibles;
}				t_map;

void	create_map(void);
void	init_map(t_map *ptmap);
void	create_tunnels(t_map *tnmap);
void	add_collectibles(t_map *map);
void	write_map(t_map *map);
void	free_map(t_map *map);
void	write_hwall(int fd, size_t size, int final);

#endif