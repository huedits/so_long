/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:19:49 by vimatheu          #+#    #+#             */
/*   Updated: 2023/01/25 02:15:19 by vimatheu         ###   ########.fr       */
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
	if (g->map.array[new_y][new_x] == '0' || g->map.array[new_y][new_x] == 'E' \
		|| g->map.array[new_y][new_x] == 'P')
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
	int		i;
	int		j;

	i = 0;
	while (i <= (h * 32) + 100)
	{
		j = 0;
		while (j <= (w * 32) + 100)
			{
				mlx_pixel_put(data->mlx, data->win, j++, i, 0x0);
			}
		++i;
	}
}

void	render_map(t_game *g)
{
	int		i;
	int		j;
	char 	*sstring;

	//mlx_put_image_to_window(g->data.mlx, g->data.win, &g->sprites.bg, 0, 0);
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
		mlx_string_put(g->data.mlx, g->data.win, 3, 40, \
			0xFFFFFF, "You are dead.");
	if (g->status == 'w')
		mlx_string_put(g->data.mlx, g->data.win, 3, 40, \
			0xFFFFFF, "You win!");
}

void	print_img_from_map(t_game *g, int x, int y)
{
	if (g->map.array[y][x] == '1')
		mlx_put_image_to_window(g->data.mlx, g->data.win, \
			g->sprites.wall, 50 + (x * 32), 50 + (y * 32));
	if (g->map.array[y][x] == 'E' && g->map.coins == 0)
		mlx_put_image_to_window(g->data.mlx, g->data.win, \
			g->sprites.door, 50 + (x * 32), 50 + (y * 32));
	if (g->map.array[y][x] == 'C')
		mlx_put_image_to_window(g->data.mlx, g->data.win, \
			g->sprites.key, 50 + (x * 32), 50 + (y * 32));
	if (g->map.array[y][x] == 'N')
		mlx_put_image_to_window(g->data.mlx, g->data.win, \
			g->sprites.slime, 50 + (x * 32), 50 + (y * 32));
	if (!(g->map.array[g->map.p_y][g->map.p_x] == 'E' && g->map.coins == 0))
		mlx_put_image_to_window(g->data.mlx, g->data.win, \
				g->sprites.knight, 50 + (g->map.p_x * 32), \
				50 + (g->map.p_y * 32));
}

int	end_game(t_game	*g)
{
	mlx_destroy_image(g->data.mlx, g->sprites.wall);
	mlx_destroy_image(g->data.mlx, g->sprites.floor);
	mlx_destroy_image(g->data.mlx, g->sprites.key);
	mlx_destroy_image(g->data.mlx, g->sprites.slime);
	mlx_destroy_image(g->data.mlx, g->sprites.knight);
	mlx_destroy_image(g->data.mlx, g->sprites.door);
	mlx_destroy_window(g->data.mlx, g->data.win);
	mlx_destroy_display(g->data.mlx);
	free(g->data.mlx);
	free_map(&g->map, 1);
	exit(0);
}
