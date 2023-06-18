/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:16:08 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/29 14:27:54 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[0][i])
		i++;
	while (data->map[j])
		j++;
	data->size_x = i;
	data->size_y = j;
}

void	collectable_init(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'C')
				data->btc_count++;
			i++;
		}
		i = 0;
		j++;
	}
}

void	player_init(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
			{
				data->player.x = i;
				data->player.y = j;
				return ;
			}
			else
				i++;
		}
		i = 0;
		j++;
	}
}

void	image_init(t_data *data)
{
	data->img.background = "./images/background.xpm";
	data->img.p_bitcoin = "./images/bitcoin.xpm";
	data->img.p_exit_door = "./images/exit_door.xpm";
	data->img.p_wall = "./images/wall.xpm";
	data->img.p_player_right = "./images/mario.xpm";
	data->img.p_end = "./images/end.xpm";
	data->img.p_player_left = "./images/left_mario.xpm";
	data->img.background = mlx_xpm_file_to_image(data->mlx,
			data->img.background, &data->img.width, &data->img.height);
	data->img.bitcoin = mlx_xpm_file_to_image(data->mlx, data->img.p_bitcoin,
			&data->img.width, &data->img.height);
	data->img.exit_door = mlx_xpm_file_to_image(data->mlx,
			data->img.p_exit_door, &data->img.width, &data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, data->img.p_wall,
			&data->img.width, &data->img.height);
	data->img.player_right = mlx_xpm_file_to_image(data->mlx,
			data->img.p_player_right, &data->img.width, &data->img.height);
	data->e = mlx_xpm_file_to_image(data->mlx, data->img.p_end,
			&data->img.width, &data->img.height);
	data->img.player_left = mlx_xpm_file_to_image(data->mlx,
			data->img.p_player_left, &data->img.width, &data->img.height);
}

void	data_init(t_data *data)
{
	map_init(data);
	chck_walls(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "so_long");
	image_init(data);
	data->player.x = 0;
	data->player.y = 0;
	player_init(data);
	data->move_count = 0;
	data->btc_count = 0;
	collectable_init(data);
	data->end = 0;
}
