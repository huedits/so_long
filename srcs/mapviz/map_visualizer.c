/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_visualizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:23:03 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/29 23:42:58 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_visualizer.h"

int main (void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Map Visualizer");
	mlx_loop(win_ptr);
	mlx_destroy_window(win_ptr, mlx_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}