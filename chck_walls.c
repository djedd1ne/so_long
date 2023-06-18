/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:44:26 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/29 14:28:57 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chck_sides(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][data->size_x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	chck_top_bottom(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (data->map[data->size_y - 1][i])
	{
		if (data->map[data->size_y - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	chck_walls(t_data *data)
{
	if (chck_sides(data) == 0 || chck_top_bottom(data) == 0)
	{
		ft_putendl_fd("Error\nMap is not closed", 2);
		free_map(data->map);
		exit(EXIT_SUCCESS);
	}
}
