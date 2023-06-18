/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:13:59 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/29 14:32:12 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	chck_arg(ac, av[1]);
	data.map = create_map(av[1]);
	chck_map(&data);
	data_init(&data);
	render(&data);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_hook(data.win, 17, 0, exitbutton, &data);
	mlx_loop(data.mlx);
	free_map(data.map);
	mlx_destroy_window(data.mlx, data.win);
	return (0);
}
