/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_visualizer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:26:34 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/30 04:46:52 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VISUALIZER_H
# define MAP_VISUALIZER_H

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 700
# define MLX_ERROR 1
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLACK_PIXEL 0x0

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

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

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

int		handle_no_event(void *data);
int		handle_keypress(int keysym, t_data *data);
int		render(t_data *data);
int		render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);
void	img_pix_put(t_img *img, int x, int y, int color);

#endif