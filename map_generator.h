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


#endif