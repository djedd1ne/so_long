/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:44:21 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/29 13:45:30 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player_left(t_data *data, int x, int y)
{
	int	offset_x;
	int	offset_y;

	offset_x = (x - data->offset_x) * IMG_W;
	offset_y = (y - data->offset_y) * IMG_H;
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img.player_left,
			offset_x, offset_y);
}
