/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:06:04 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/29 20:39:45 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_GENERATOR_H
# define MAP_GENERATOR_H

# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**array;
	int	width;
	int	height;
	int	max_lenght;
	int	max_tunnels;
	int	collectibles;
}				t_map;

void	create_map(void);
void	init_map(t_map *ptmap);
void	create_tunnels(t_map *tnmap);
void	add_collectibles(t_map *map);
void	write_map(t_map *map);
void	free_map(t_map *map, int height);
void	write_hwall(int fd, int size, int final);
void	get_random_dir(int *new_dir);
void	new_tunnel(t_map *map, int *rdir, int *cpos);

#endif