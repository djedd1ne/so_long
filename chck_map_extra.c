/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_map_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:43:43 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/29 14:31:58 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chck_empty_map(t_data *data)
{
	if (data->map == NULL)
	{
		ft_putendl_fd("Error\nmap is empty\n", 2);
		free_map(data->map);
		exit(EXIT_SUCCESS);
	}
}

void	chck_rectangle(t_data *data)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
			i++;
		if (j > 0 && i != len)
		{
			ft_putendl_fd("Error\nmap is not rectangular", 2);
			free_map(data->map);
			exit(EXIT_SUCCESS);
		}
		len = i;
		i = 0;
		j++;
	}
}

void	chck_map(t_data *data)
{
	chck_empty_map(data);
	chck_rectangle(data);
	chck_components(data);
	chck_collectible(data);
	chck_exit(data);
	chck_player(data);
	chck_free_s(data);
}
