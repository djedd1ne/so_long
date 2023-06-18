/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_extension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:06:28 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/29 10:33:55 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chck_arg(int ac, char *file_name)
{
	size_t	len;
	char	*str;

	len = 0;
	str = NULL;
	if (ac != 2)
	{
		ft_putendl_fd("Error\nUsage : ./so_long <filename.ber>\n", 2);
		exit(EXIT_SUCCESS);
	}
	len = ft_strlen(file_name);
	str = ft_strnstr(file_name, ".ber", len);
	if (str == NULL || str == file_name || *(str + 4) != '\0')
	{
		ft_putendl_fd("Error\nUse a valid .ber file", 2);
		exit(EXIT_SUCCESS);
	}
}
