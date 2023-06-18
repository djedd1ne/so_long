/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:22:01 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/29 14:31:47 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chck_components(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] != '0' && data->map[j][i] != '1'
			&& data->map[j][i] != 'C' && data->map[j][i] != 'E'
			&& data->map[j][i] != 'P')
			{
				ft_putendl_fd("Error\nMap error : Invalid components", 2);
				free_map(data->map);
				exit(EXIT_SUCCESS);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	chck_collectible(t_data	*data)
{
	int	i;
	int	j;
	int	btc_count;

	i = 0;
	j = 0;
	btc_count = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'C')
				btc_count++;
			i++;
		}
		i = 0;
		j++;
	}
	if (btc_count < 1)
	{
		ft_putendl_fd("Error\nNo collectible found", 2);
		free_map(data->map);
		exit(EXIT_SUCCESS);
	}
}

void	chck_exit(t_data *data)
{
	int	i;
	int	j;
	int	exit_count;

	i = 0;
	j = 0;
	exit_count = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'E')
				exit_count++;
			i++;
		}
		i = 0;
		j++;
	}
	if (exit_count < 1)
	{
		ft_putendl_fd("Error\nNo Exit found", 2);
		free_map(data->map);
		exit(EXIT_FAILURE);
	}
}

void	chck_player(t_data	*data)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	j = 0;
	player_count = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
				player_count++;
			i++;
		}
		i = 0;
		j++;
	}
	if (player_count != 1)
	{
		ft_putendl_fd("Error\nYou need one player", 2);
		free_map(data->map);
		exit(EXIT_SUCCESS);
	}
}

void	chck_free_s(t_data *data)
{
	int	i;
	int	j;
	int	free_s_count;

	i = 0;
	j = 0;
	free_s_count = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == '0')
				free_s_count++;
			i++;
		}
		i = 0;
		j++;
	}
	if (free_s_count < 1)
	{
		ft_putendl_fd("Error\nNo Free space found", 2);
		free_map(data->map);
		exit(EXIT_FAILURE);
	}
}
