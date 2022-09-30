/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_visualizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:23:03 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/30 07:53:39 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_visualizer.h"

int main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Map Visualizer");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	create_handlers(&data);
	/* render(&data); */
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}

int	render(t_data *data)
{
	int	i;

	if (data->win_ptr == NULL)
		return (1);
	i = 0;
	while (i < WINDOW_WIDTH - 50)
	{
		render_background(&data->img, BLACK_PIXEL);
		render_rect(&data->img, (t_rect){i, 0, 50, WINDOW_HEIGHT, WHITE_PIXEL});
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		i += 50;
		usleep(40000);
	}
	while (i > 0)
	{
		render_background(&data->img, BLACK_PIXEL);
		render_rect(&data->img, (t_rect){i, 0, 50, WINDOW_HEIGHT, WHITE_PIXEL});
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
		i -= 50;
		usleep(40000);
	}
	return (0);
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= WINDOW_HEIGHT)
	{
		j = 0;
		while (j <= WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
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