/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:20:36 by djmekki           #+#    #+#             */
/*   Updated: 2022/09/29 14:29:56 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include<stdlib.h>
# include<stdio.h>
# include<errno.h>
# include<unistd.h>
# include<fcntl.h>
# include "Libft/libft.h"
# include "mlx/mlx.h"

# define IMG_H 32
# define IMG_W 32
# define WIDTH 1280
# define HEIGHT 640
# define DISTANCE_X 20
# define DISTANCE_Y 10

/* ****************************************** */
/*					struct			  		  */
/* ****************************************** */

typedef struct s_player
{
	int		x;
	int		y;
}			t_p;

typedef struct s_img
{
	void	*player_right;
	void	*player_left;
	void	*background;
	void	*bitcoin;
	void	*exit_door;
	void	*wall;
	int		width;
	int		height;
	char	*p_player_right;
	char	*p_player_left;
	char	*p_background;
	char	*p_bitcoin;
	char	*p_exit_door;
	char	*p_wall;
	char	*p_end;
}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		move_count;
	int		btc_count;
	t_img	img;
	int		collectable;
	t_p		player;
	int		end;
	char	**map;
	int		size_x;
	int		size_y;
	int		offset_x;
	int		offset_y;
	void	*e;
}			t_data;

/* ****************************************** */
/*					functions		  		  */
/* ****************************************** */

void	mlx_image_init(t_data *data);
void	map_init(t_data *data);
void	collectable_init(t_data *data);
void	player_init(t_data *data);
void	data_init(t_data *data);

void	chck_map(t_data *data);
void	chck_empty_map(t_data *data);
void	chck_rectangle(t_data *data);
void	chck_components(t_data *data);
void	chck_player(t_data	*data);
void	chck_exit(t_data *data);
void	chck_collectible(t_data	*data);
void	chck_walls(t_data *data);
void	chck_free_s(t_data *data);

char	**allocate_map(int fd);
void	fill_trimmed_line(char **map, int fd);
char	**create_map(char *file_name);
void	chck_arg(int ac, char *file_name);
int		key_hook(int keycode, t_data *data);
int		exitbutton(t_data *_data);
void	free_map(char **map);

void	put_background(t_data *data, int x, int y);
void	put_player(t_data *data, int x, int y);
void	put_bitcoin(t_data *data, int x, int y);
void	put_wall(t_data *data, int x, int y);
void	put_exit(t_data *data, int x, int y);

int		offsety(t_data *data);
int		offsetx(t_data *data);
void	render(t_data *data);

void	move_left(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_up(t_data *data);
void	render_2(t_data *data);
void	put_player_left(t_data *data, int x, int y);
#endif
