/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:58:30 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/29 10:06:39 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	if (data->map[y][x - 1] != '1')
	{
		if (data->map[y][x] != 'E')
			data->map[y][x] = '0';
		if (data->map[y][x - 1] == 'C')
			data->btc_count--;
		if (data->map[y][x - 1] != 'E')
			data->map[y][x - 1] = 'P';
		data->player.x = x - 1;
		data->move_count++;
		render_2(data);
		if (data->map[y][x - 1] == 'E' &&
			data->btc_count == 0 && data->end == 0)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->e, 512, 192);
			data->end = 1;
		}
		ft_putnbr_fd(data->move_count, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_down(t_data *data)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	if (data->map[y + 1][x] != '1')
	{
		if (data->map[y][x] != 'E')
			data->map[y][x] = '0';
		if (data->map[y + 1][x] == 'C')
			data->btc_count--;
		if (data->map[y + 1][x] != 'E')
			data->map[y + 1][x] = 'P';
		data->player.y = y + 1;
		data->move_count++;
		render(data);
		if (data->map[y + 1][x] == 'E' &&
			data->btc_count == 0 && data->end == 0)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->e, 512, 192);
			data->end = 1;
		}
		ft_putnbr_fd(data->move_count, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	if (data->map[y][x + 1] != '1')
	{
		if (data->map[y][x] != 'E')
			data->map[y][x] = '0';
		if (data->map[y][x + 1] == 'C')
			data->btc_count--;
		if (data->map[y][x + 1] != 'E')
			data->map[y][x + 1] = 'P';
		data->player.x = x + 1;
		data->move_count++;
		render(data);
		if (data->map[y][x + 1] == 'E' &&
			data->btc_count == 0 && data->end == 0)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->e, 512, 192);
			data->end = 1;
		}
		ft_putnbr_fd(data->move_count, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_up(t_data *data)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	if (data->map[y - 1][x] != '1')
	{
		if (data->map[y][x] != 'E')
			data->map[y][x] = '0';
		if (data->map[y - 1][x] == 'C')
			data->btc_count--;
		if (data->map[y - 1][x] != 'E')
			data->map[y - 1][x] = 'P';
		data->player.y = y - 1;
		data->move_count++;
		render(data);
		if (data->map[y - 1][x] == 'E' &&
			data->btc_count == 0 && data->end == 0)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->e, 512, 192);
			data->end = 1;
		}
		ft_putnbr_fd(data->move_count, 1);
		ft_putchar_fd('\n', 1);
	}
}
