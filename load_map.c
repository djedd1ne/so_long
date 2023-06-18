/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:12:42 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/26 08:30:24 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**allocate_map(int fd)
{
	char	**map;
	char	*tmp;
	int		line_count;

	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	line_count = 0;
	while (tmp)
	{
		line_count++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (map == NULL)
		return (NULL);
	map[line_count] = NULL;
	return (map);
}

void	fill_trimmed_line(char **map, int fd)
{
	char	*tmp;
	char	*no_newline;
	int		line_n;

	tmp = get_next_line(fd);
	if (!tmp)
		return ;
	line_n = 0;
	while (tmp)
	{
		no_newline = ft_strtrim(tmp, "\n");
		map[line_n] = no_newline;
		free(tmp);
		tmp = get_next_line(fd);
		line_n++;
	}
	free(tmp);
	return ;
}

char	**create_map(char *file_name)
{
	char	*path_map;
	char	**map;
	int		fd;

	path_map = ft_strjoin("./maps/", file_name);
	fd = open(path_map, O_RDONLY);
	if (fd == -1)
	{
		free(path_map);
		perror("Error\n");
		exit(EXIT_SUCCESS);
	}
	map = allocate_map(fd);
	close(fd);
	fd = open(path_map, O_RDONLY);
	if (fd == -1)
	{
		free(path_map);
		ft_putendl_fd("Error\n", 2);
		exit(EXIT_SUCCESS);
	}
	free(path_map);
	fill_trimmed_line(map, fd);
	close(fd);
	return (map);
}
