/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:19:49 by vimatheu          #+#    #+#             */
/*   Updated: 2022/12/13 22:07:15 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_new_pos(t_game *g, int new_x, int new_y)
{
	if (g->map.array[new_y][new_x] == '1')
		return ;
	if (g->map.array[new_y][new_x] == 'N')
		g->status = 'd';
	if (g->map.array[new_y][new_x] == 'C')
	{
		g->map.coins--;
		g->map.array[new_y][new_x] = '0';
	}
	if (g->map.array[new_y][new_x] == '0' || g->map.array[new_y][new_x] == 'E')
	{
		g->map.p_x = new_x;
		g->map.p_y = new_y;
	}
	g->steps++;
	if (g->map.array[new_y][new_x] == 'E' && g->map.coins == 0)
		g->status = 'w';
	render_map(g);
}

void	render_background(t_data *data, int w, int h)
{
	int	i;
	int	j;

	i = 0;
	while (i <= h + 100)
	{
		j = 0;
		while (j <= w + 100)
			mlx_pixel_put(data->mlx, data->win, j++, i, 0x0);
		++i;
	}
}

void	render_map(t_game *g)
{
	int		i;
	int		j;
	char 	*sstring;

	render_background(&g->data, g->map.width, g->map.height);
	sstring = ft_itoa(g->steps);
	mlx_string_put(g->data.mlx, g->data.win, 3, 25, 0xFFFFFF, "Steps: ");
	mlx_string_put(g->data.mlx, g->data.win, 50, 25, 0xFFFFFF, sstring);
	free(sstring);
	i = 0;
	while (i < g->map.height)
	{
		j = 0;
		while (j < g->map.width)
		{
			print_img_from_map(g, j, i);
			j++;
		}
		i++;
	}
	if (g->status == 'd')
		mlx_string_put(g->data.mlx, g->data.win, 3, 5,
			0xFFFFFF, "You are dead.");
	if (g->status == 'w')
		mlx_string_put(g->data.mlx, g->data.win, 3, 5,
			0xFFFFFF, "You win!");
}

void	print_img_from_map(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->data.mlx, g->data.win, \
			g->sprites.floor, 100 + (x * 16), 100 + (y * 16));
	if (g->map.array[y][x] == '1')
		mlx_put_image_to_window(g->data.mlx, g->data.win, \
			g->sprites.wall, 100 + (x * 16), 100 + (y * 16));
	if (g->map.array[y][x] == 'E' && g->map.coins == 0)
		mlx_put_image_to_window(g->data.mlx, g->data.win, \
			g->sprites.door, 100 + (x * 16), 100 + (y * 16));
	if (g->map.array[y][x] == 'C')
		mlx_put_image_to_window(g->data.mlx, g->data.win, \
			g->sprites.key, 100 + (x * 16), 100 + (y * 16));
	if (g->map.array[y][x] == 'N')
		mlx_put_image_to_window(g->data.mlx, g->data.win, \
			g->sprites.slime, 100 + (x * 16), 100 + (y * 16));
}

void	img_sprite_put(t_img *img, void *sprite, int x, int y)
{
	char	*pixel;
	char	*csprite;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	csprite = (char *) sprite;
	while (*csprite)
		*pixel++ = *csprite++;
}
