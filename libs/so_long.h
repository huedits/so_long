/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:05:43 by vimatheu          #+#    #+#             */
/*   Updated: 2023/01/25 02:07:25 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MLX_ERROR 1
# define PWALL "srcs/sprites/wall.xpm"
# define PFLOOR "srcs/sprites/floor.xpm"
# define PKNIGHT "srcs/sprites/knight.xpm"
# define PSLIME "srcs/sprites/slime.xpm"
# define PDOOR "srcs/sprites/door.xpm"
# define PKEY "srcs/sprites/key.xpm"

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

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
	void	*key;
	void	*slime;
	void	*knight;
	void	*door;
}	t_sprites;

typedef struct s_data
{
	void	*mlx;
	void	*win;
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
	t_sprites	sprites;
	size_t		steps;
	char		status;
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
void	exit_error(char *str, t_map *map, int nf);

///////////////////////////////////////////////////////
//////////////////// Game Status //////////////////////
///////////////////////////////////////////////////////

int		init_window(t_data *data, char *win_name, int w, int h);
int		end_game(t_game	*g);

///////////////////////////////////////////////////////
///////////////////// Handlers ////////////////////////
///////////////////////////////////////////////////////

int		handle_keypress(int keysym, t_game *game);
int		handle_x_pressed(t_game *game);
void	create_handlers(t_game *game);

///////////////////////////////////////////////////////
///////////////////// Gameplay ////////////////////////
///////////////////////////////////////////////////////

void	check_new_pos(t_game *g, int new_x, int new_y);
void	create_background(t_game *g, t_img *bg);
/*void	render_background(t_data *data, int w, int h);*/
void	render_map(t_game *g);
void	print_img_from_map(t_game *g, int x, int y);
void	convert_sprites(t_sprites *spr, t_data *data);

#endif