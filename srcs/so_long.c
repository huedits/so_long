/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:05:57 by vimatheu          #+#    #+#             */
/*   Updated: 2022/11/09 16:23:04 by vimatheu         ###   ########.fr       */
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
	/* print_map_info(&game.map);
	free_map(&game.map, 1); */
	if (init_window(&game.data, ft_strjoin("so_long -> ", game.map.name)))
		free_map(&game.map, 1);
	game.status = 'p';
	create_handlers(&game.data);
	mlx_loop(game.data.mlx_ptr);
	mlx_destroy_display(game.data.mlx_ptr);
	free(game.data.mlx_ptr);
	free_map(&game.map, 1);
}

int	init_window(t_data *data, char *win_name)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WWIDTH, WHEIGHT, win_name);
	free(win_name);
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		free(data->mlx_ptr);
		return (MLX_ERROR);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WWIDTH, WHEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
		&data->img.line_len, &data->img.endian);
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{

		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
