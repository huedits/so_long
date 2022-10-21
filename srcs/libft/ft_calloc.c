/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:31:03 by vimatheu          #+#    #+#             */
/*   Updated: 2022/08/31 00:47:49 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (size > (~(1 << 31) / count))
		return (NULL);
	mem = malloc (size * count);
	if (mem != NULL)
		ft_bzero(mem, (count * size));
	return (mem);
}
