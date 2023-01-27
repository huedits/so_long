/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:05:57 by vimatheu          #+#    #+#             */
/*   Updated: 2023/01/27 23:39:04 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		exit_error("Error\nInvalid number of arguments.\n", &game.map, 0);
	game.map.name = ft_strtrim(argv[1], " ");
	is_valid(&game.map);
	if (init_window(&game.data, ft_strjoin("so_long -> ", game.map.name), \
			game.map.width, game.map.height))
	{
		free_map(&game.map, 1);
		free(game.data.mlx);
		return (0);
	}
	game.status = 'p';
	game.steps = 0;
	create_handlers(&game);
	convert_sprites(&game.sprites, &game.data);
	render_map(&game);
	mlx_loop(game.data.mlx);
}

int	init_window(t_data *data, char *win_name, int w, int h)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (MLX_ERROR);
	data->win = mlx_new_window(data->mlx, (w * 32) + 100, (h * 32) + 100, \
			win_name);
	free(win_name);
	if (data->win == NULL)
	{
		free(data->win);
		return (MLX_ERROR);
	}
	data->img.mlx_img = mlx_new_image(data->mlx, (w * 32) + 100, \
			(h * 32) + 100);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
			&data->img.line_len, &data->img.endian);
	return (0);
}

void	convert_sprites(t_sprites *spr, t_data *data)
{
	int	w;
	int	h;

	spr->wall = mlx_xpm_file_to_image(data->mlx, PWALL, &w, &h);
	spr->floor = mlx_xpm_file_to_image(data->mlx, PFLOOR, &w, &h);
	spr->key = mlx_xpm_file_to_image(data->mlx, PKEY, &w, &h);
	spr->knight = mlx_xpm_file_to_image(data->mlx, PKNIGHT, &w, &h);
	spr->slime = mlx_xpm_file_to_image(data->mlx, PSLIME, &w, &h);
	spr->door = mlx_xpm_file_to_image(data->mlx, PDOOR, &w, &h);
}
