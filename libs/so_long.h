/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:05:43 by vimatheu          #+#    #+#             */
/*   Updated: 2022/10/21 22:14:11 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "get_next_line.h"
# include "libft.h"

typedef struct s_map
{
	char	**array;
	char	*name;
	int		width;
	int		height;
	int		coins;
	int		p_x;
	int		p_y;
}	t_map;

typedef struct s_game
{
	t_map		map;
	int			steps;
	int			status;
}	t_game;

void	free_map(t_map *map);
void	generate_map(void);
void	get_map(t_map *map);
char	*read_map(t_map	*map);
void	get_player_pos(t_map *map);
void	is_valid(t_map *map);
void	is_rectangular(t_map *map);
void	check_borders(t_map *map);
void	check_path(t_map *map);

#endif