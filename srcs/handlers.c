/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 07:06:59 by vimatheu          #+#    #+#             */
/*   Updated: 2022/11/10 00:14:38 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_handlers(t_game *game)
{
	mlx_loop_hook(game->data.mlx_ptr, &handle_no_event, &game->data);
	mlx_hook(game->data.win_ptr, KeyPress, KeyPressMask, &handle_keypress,
		game);
	mlx_hook(game->data.win_ptr, DestroyNotify, StructureNotifyMask,
		&handle_x_pressed, &game->data);
}

int	handle_no_event(t_game *game)
{
	char *sstring;
	
	render_background(&game->data);
	sstring = ft_itoa(game->steps);
	mlx_string_put(game->data.mlx_ptr, game->data.win_ptr, 3, 3, 0xFFFFFF, "Steps: ");
	mlx_string_put(game->data.mlx_ptr, game->data.win_ptr, 15, 3, 0xFFFFFF, sstring);
	free(sstring);
	if (game->status == 'p')
		render_map(game);
	if (game->status == 'd')
		;
	if (game->status == 'w')
		;
	return (0);
}

int	handle_keypress(t_game *game, int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
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
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}
