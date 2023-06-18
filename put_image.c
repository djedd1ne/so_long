/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:37:04 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/29 09:19:15 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_data *data, int x, int y)
{
	int	offset_x;
	int	offset_y;

	offset_x = (x - data->offset_x) * IMG_W;
	offset_y = (y - data->offset_y) * IMG_H;
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img.player_right,
			offset_x, offset_y);
}

void	put_background(t_data *data, int x, int y)
{
	int	offset_x;
	int	offset_y;

	offset_x = (x - data->offset_x) * IMG_W;
	offset_y = (y - data->offset_y) * IMG_H;
	if (data->map[y][x])
		mlx_put_image_to_window(data->mlx, data->win, data->img.background,
			offset_x, offset_y);
}

void	put_bitcoin(t_data *data, int x, int y)
{
	int	offset_x;
	int	offset_y;

	offset_x = (x - data->offset_x) * IMG_W;
	offset_y = (y - data->offset_y) * IMG_H;
	if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.bitcoin,
			offset_x, offset_y);
}

void	put_wall(t_data *data, int x, int y)
{
	int	offset_x;
	int	offset_y;

	offset_x = (x - data->offset_x) * IMG_W;
	offset_y = (y - data->offset_y) * IMG_H;
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall,
			offset_x, offset_y);
}

void	put_exit(t_data *data, int x, int y)
{
	int	offset_x;
	int	offset_y;

	offset_x = (x - data->offset_x) * IMG_W;
	offset_y = (y - data->offset_y) * IMG_H;
	if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit_door,
			offset_x, offset_y);
}
