/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 07:06:59 by vimatheu          #+#    #+#             */
/*   Updated: 2022/10/31 23:41:11 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void create_handlers(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &handle_x_pressed, data);
}

int	handle_no_event(t_data *data)
{
	//????
	if (data)
		;
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	/* if (keysym == XK_Left || keysym == XK_a || keysym == XK_A)
		move_left();
	if (keysym == XK_Up || keysym == XK_w || keysym == XK_W)
		move_up();
	if (keysym == XK_Right || keysym == XK_d || keysym == XK_D)
		move_right();
	if (keysym == XK_Down || keysym == XK_s || keysym == XK_S)
		move_down(); */
	return (0);
}

int	handle_x_pressed(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}