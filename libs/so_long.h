/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:05:43 by vimatheu          #+#    #+#             */
/*   Updated: 2022/10/20 22:13:29 by vimatheu         ###   ########.fr       */
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

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char	**array;
	int		width;
	int		height;
	int		coins;
}	t_map;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	int			steps;
	int			status;
}	t_game;

void	generate_map(void);
char	*read_map(t_map	*map);
void	write_array(t_map *map);

#endif