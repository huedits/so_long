/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:19:49 by vimatheu          #+#    #+#             */
/*   Updated: 2022/11/18 22:21:38 by vimatheu         ###   ########.fr       */
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
	mlx_string_put(g->data.mlx, g->data.win, 3, 20, 0xFFFFFF, "Steps: ");
	mlx_string_put(g->data.mlx, g->data.win, 15, 20, 0xFFFFFF, sstring);
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
}

void	print_img_from_map(t_game *g, int x, int y)
{
	img_sprite_put(&g->data.img, g->sprites.floor, x * 16, y * 16);
	if (g->map.array[y][x] == '1')
		img_sprite_put(&g->data.img, g->sprites.wall, x * 16, y * 16);
	if (g->map.array[y][x] == 'E' && g->map.coins == 0)
		img_sprite_put(&g->data.img, g->sprites.door, x * 16, y * 16);
	if (g->map.array[y][x] == 'C')
		img_sprite_put(&g->data.img, g->sprites.key, x * 16, y * 16);
	if (g->map.array[y][x] == 'N')
		img_sprite_put(&g->data.img, g->sprites.slime, x * 16, y * 16);
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
