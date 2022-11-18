/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 07:06:59 by vimatheu          #+#    #+#             */
/*   Updated: 2022/11/18 22:12:24 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_handlers(t_game *game)
{
	mlx_loop_hook(game->data.mlx, &handle_no_event, game);
	mlx_hook(game->data.win, KeyPress, KeyPressMask, &handle_keypress,
		game);
	mlx_hook(game->data.win, DestroyNotify, StructureNotifyMask,
		&handle_x_pressed, &game->data);
}

int	handle_no_event(t_game *game)
{	
	if (game->status == 'p')
	{
		render_map(game);
		img_sprite_put(&game->data.img, game->sprites.knight,
			game->map.p_x * 16, game->map.p_y * 16);
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->data.img.mlx_img, 50, 50);
	}
	if (game->status == 'd')
	{
		render_map(game);
		mlx_string_put(game->data.mlx, game->data.win, 3, 5,
			0xFFFFFF, "You are dead.");
	}
	if (game->status == 'w')
	{
		render_map(game);
		mlx_string_put(game->data.mlx, game->data.win, 3, 5,
			0xFFFFFF, "You win!");
	}
	return (0);
}

int	handle_keypress(t_game *game, int keysym)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->data.mlx, game->data.win);
		game->data.win = NULL;
	}
	if (game->status == 'p')
	{	
		if (keysym == XK_Left || keysym == XK_a || keysym == XK_A)
			check_new_pos(game, game->map.p_x - 1, game->map.p_y);
		if (keysym == XK_Up || keysym == XK_w || keysym == XK_W)
			check_new_pos(game, game->map.p_x, game->map.p_y - 1);
		if (keysym == XK_Right || keysym == XK_d || keysym == XK_D)
			check_new_pos(game, game->map.p_x + 1, game->map.p_y);
		if (keysym == XK_Down || keysym == XK_s || keysym == XK_S)
			check_new_pos(game, game->map.p_x, game->map.p_y + 1);
	}
	return (0);
}

int	handle_x_pressed(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	return (0);
}
