/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:41:28 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/29 08:54:47 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		free_map(data->map);
		exit(EXIT_SUCCESS);
		return (0);
	}
	if (data->end == 0)
	{
		if (keycode == 123 || keycode == 0)
			move_left(data);
		if (keycode == 125 || keycode == 1)
			move_down(data);
		if (keycode == 124 || keycode == 2)
			move_right(data);
		if (keycode == 126 || keycode == 13)
			move_up(data);
	}	
	return (0);
}
