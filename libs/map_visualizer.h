/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_visualizer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:26:34 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/30 07:06:26 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VISUALIZER_H
# define MAP_VISUALIZER_H

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 700
# define MLX_ERROR 1
# define BLACK_PIXEL 0x0
# define WHITE_PIXEL 0xFFFFFF

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
# include <stdio.h>
# include <unistd.h>
# include "handlers.h"

int		render(t_data *data);
int		render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);
void	img_pix_put(t_img *img, int x, int y, int color);

#endif