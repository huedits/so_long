/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 07:06:59 by vimatheu          #+#    #+#             */
/*   Updated: 2022/12/13 22:05:35 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_handlers(t_game *game)
{
	mlx_hook(game->data.win, KeyPress, KeyPressMask, &handle_keypress,
		game);
	mlx_hook(game->data.win, DestroyNotify, StructureNotifyMask,
		&handle_x_pressed, &game->data);
}

int	handle_keypress(int keysym, t_game *game)
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
