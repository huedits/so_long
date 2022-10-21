/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:05:57 by vimatheu          #+#    #+#             */
/*   Updated: 2022/10/21 21:51:14 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int arc, char *argv[])
{
	t_game	game;
	char	*map_name;

	if (argc != 2)
		write(1, "Error\nInvalid number of arguments.\n", 35);
		return (0);
	game.map.name = ft_strtrim(argv[1]);
	is_valid(&game.map);
}
