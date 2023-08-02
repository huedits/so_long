/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:19:49 by vimatheu          #+#    #+#             */
/*   Updated: 2023/01/27 23:44:40 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_new_pos(t_game *g, int new_x, int new_y)
{
	if (g->map.array[new_y][new_x] == ENUM_COIN)
	{
		g->map.coins--;
		g->map.array[new_y][new_x] = ENUM_SPACE;
	}
	if (g->map.array[new_y][new_x] == ENUM_ENEMY)
		g->status = 'd';
	if (g->map.array[new_y][new_x] == ENUM_EXIT && g->map.coins == 0)
		g->status = 'w';
	if (g->map.array[new_y][new_x] != ENUM_WALL)
	{
		g->map.p_x = new_x;
		g->map.p_y = new_y;
		g->steps++;
		render_map(g);
	}
}

int	render_map(t_game *g)
{
	int		i;
	int		j;
	char	*sstring;

	mlx_put_image_to_window(g->data.mlx, g->data.win, g->data.img.mlx_img, \
			0, 0);
	sstring = ft_itoa(g->steps);
	mlx_string_put(g->data.mlx, g->data.win, 3, 25, 0xFFFFFF, "Steps: ");
	mlx_string_put(g->data.mlx, g->data.win, 50, 25, 0xFFFFFF, sstring);
	free(sstring);
	i = 0;
	while (i < g->map.height)
	{
		j = 0;
		while (j < g->map.width)
			print_img_from_map(g, j++, i);
		i++;
	}
	if (g->status == 'd')
		mlx_string_put(g->data.mlx, g->data.win, 3, 40, \
			0xFFFFFF, "You are dead.");
	if (g->status == 'w')
		mlx_string_put(g->data.mlx, g->data.win, 3, 40, \
			0xFFFFFF, "You win!");
	return (0);
}

void	print_img_from_map(t_game *g, int x, int y)
{
	if (g->map.array[y][x] == ENUM_WALL)
		mlx_put_image_to_window(g->data.mlx, g->data.win, \
			g->sprites.wall, 50 + (x * 32), 50 + (y * 32));
	else if (g->map.array[y][x] == ENUM_EXIT && g->map.coins == 0)
		mlx_put_image_to_window(g->data.mlx, g->data.win, \
			g->sprites.door, 50 + (x * 32), 50 + (y * 32));
	else if (g->map.array[y][x] == ENUM_COIN)
		mlx_put_image_to_window(g->data.mlx, g->data.win, \
			g->sprites.key, 50 + (x * 32), 50 + (y * 32));
	else if (g->map.array[y][x] == ENUM_ENEMY)
		mlx_put_image_to_window(g->data.mlx, g->data.win, \
			g->sprites.slime, 50 + (x * 32), 50 + (y * 32));
	else
		mlx_put_image_to_window(g->data.mlx, g->data.win, \
			g->sprites.floor, 50 + (x * 32), 50 + (y * 32));
	if (g->status == 'p')
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
	mlx_destroy_image(g->data.mlx, g->data.img.mlx_img);
	mlx_destroy_window(g->data.mlx, g->data.win);
	mlx_destroy_display(g->data.mlx);
	free(g->data.mlx);
	free_map(&g->map, 1);
	exit(0);
}
