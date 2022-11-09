/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:05:43 by vimatheu          #+#    #+#             */
/*   Updated: 2022/10/31 23:30:49 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WWIDTH 900
# define WHEIGHT 700
# define MLX_ERROR 1

# include "get_next_line.h"
# include <stdio.h>
# include <sys/wait.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

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
	t_data		data;
	size_t		steps;
	int			status;
}	t_game;

///////////////////////////////////////////////////////
/////////////////// Map Validation ////////////////////
///////////////////////////////////////////////////////

void	free_map(t_map *map, int all);
void	generate_map(void);
void	get_map(t_map *map);
char	*read_map(t_map	*map);
void	get_player_pos(t_map *map);
void	is_valid(t_map *map);
void	is_rectangular(t_map *map);
void	check_borders(t_map *map);
int		check_path(t_map *map, int x, int y);
int		get_next_path(t_map *mp, int y, int x);
int		check_mapstr(t_map *map, char *str);
void	print_map_info(t_map *map);
void	exit_error(char *str, t_map *map, int nf);

///////////////////////////////////////////////////////
//////////////////// Game Start ///////////////////////
///////////////////////////////////////////////////////

int		init_window(t_data *data, char *win_name);
void	img_pix_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int color);

///////////////////////////////////////////////////////
///////////////////// Handlers ////////////////////////
///////////////////////////////////////////////////////

int		handle_no_event(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_x_pressed(t_data *data);
void	create_handlers(t_data *data);

#endif