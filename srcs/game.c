/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:19:49 by vimatheu          #+#    #+#             */
/*   Updated: 2022/11/09 18:44:28 by vimatheu         ###   ########.fr       */
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

void	render_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i <= WHEIGHT)
	{
		j = 0;
		while (j <= WWIDTH)
			img_pix_put(data->mlx_ptr, data->win_ptr, j++, i, 0x0);
		++i;
	}
}

void	render_map(t_game *g)
{
	int		i;
	int		j;
	char	*img;

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
	mlx_put_image_to_window(g->data.mlx_ptr, g->data.win_ptr, PFLOOR
		x * 16, y * 16);
	if (g->map.array[y][x] == '1')
		mlx_put_image_to_window(g->data.mlx_ptr, g->data.win_ptr, PWALL
			x * 16, y * 16);
	if (g->map.array[y][x] == 'E' && g->map.coins > 0)
		mlx_put_image_to_window(g->data.mlx_ptr, g->data.win_ptr, PCDOOR
			x * 16, y * 16);
	if (g->map.array[y][x] == 'E' && g->map.coins == 0)
		mlx_put_image_to_window(g->data.mlx_ptr, g->data.win_ptr, PODOOR
			x * 16, y * 16);
	if (g->map.array[y][x] == 'C')
		mlx_put_image_to_window(g->data.mlx_ptr, g->data.win_ptr, PKEY
			x * 16, y * 16);
	mlx_put_image_to_window(g->data.mlx_ptr, g->data.win_ptr, PKNIGHT
		g->map.p_x * 16, g->map.p_y * 16);
}