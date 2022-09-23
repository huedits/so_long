#ifndef MAP_GENERATOR_H
# define MAP_GENERATOR_H

# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_map
{
	char	**array;
	size_t	width;
	size_t	height;
	size_t	max_lenght;
	size_t	max_tunnels;
}				t_map;

void	create_map(void);
int		init_map(t_map *ptmap);
void	create_tunnels(t_map *tnmap);

#endif