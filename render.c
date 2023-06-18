/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:21:01 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/29 10:53:49 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	offsetx(t_data *data)
{
	int	offset_x;
	int	correction_x;

	offset_x = 0;
	correction_x = 0;
	if (data->player.x > DISTANCE_X)
	{
		offset_x = data->player.x - DISTANCE_X;
		if (data->player.x > data->size_x - DISTANCE_X)
		{
			correction_x = data->player.x + DISTANCE_X - data->size_x;
			offset_x = offset_x - correction_x;
			if (offset_x < 0)
				offset_x = 0;
		}
		data->offset_x = offset_x;
		return (offset_x);
	}
	data->offset_x = 0;
	return (0);
}

int	offsety(t_data *data)
{
	int	offset_y;
	int	correction_y;

	offset_y = 0;
	correction_y = 0;
	if (data->player.y > DISTANCE_Y)
	{
		offset_y = data->player.y - DISTANCE_Y;
		if (data->player.y > data->size_y - DISTANCE_Y)
		{
			correction_y = data->player.y + DISTANCE_Y - data->size_y;
			offset_y = offset_y - correction_y;
			if (offset_y < 0)
				offset_y = 0;
		}
		data->offset_y = offset_y;
		return (offset_y);
	}
	data->offset_y = 0;
	return (0);
}

void	render(t_data *data)
{
	int	i;
	int	j;

	i = offsetx(data);
	j = offsety(data);
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			put_background(data, i, j);
			put_wall(data, i, j);
			put_bitcoin(data, i, j);
			put_exit(data, i, j);
			put_player(data, i, j);
			i++;
		}
		i = data->offset_x;
		j++;
	}
}

void	render_2(t_data *data)
{
	int	i;
	int	j;

	i = offsetx(data);
	j = offsety(data);
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			put_background(data, i, j);
			put_wall(data, i, j);
			put_bitcoin(data, i, j);
			put_exit(data, i, j);
			put_player_left(data, i, j);
			i++;
		}
		i = data->offset_x;
		j++;
	}
}
