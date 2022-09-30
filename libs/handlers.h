/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 07:05:24 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/30 07:06:13 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include <X11/X.h>
# include <X11/keysym.h>

int		handle_no_event(void *data);
int		handle_keypress(int keysym, t_data *data);

#endif