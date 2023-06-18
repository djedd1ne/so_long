LIBFT = cd Libft && make
LIB   = Libft/libft.a

LIBMINI = cd mlx && make
LIBX    = mlx/libmlx.a

SRC = chck_extension.c chck_walls.c chck_map.c chck_map_extra.c\
 		close_game.c data_init.c key_press.c load_map.c move_player.c \
		put_image.c put_image_extra.c so_long.c
OBJ = $(SRC:%.c=%.o)

MAN = render.c
MOBJ = $(MAN:%.c=%.o)

BONUS = render_bonus.c
BONUSOBJ = $(BONUS:%.c=%.o)

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIB):
	$(LIBFT)

$(LIBX):
	$(LIBMINI)

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(LIB) $(LIBX) $(OBJ) $(MOBJ)
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIB) $(OBJ) $(MOBJ) -o $@

bonus: $(LIB) $(LIBX) $(OBJ) $(BONUSOBJ) $(NAME)
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIB) $(OBJ) $(BONUSOBJ) -o $(NAME)
clean: 
	rm -rf $(OBJ) $(MOBJ) $(BONUSOBJ)
	cd Libft && make clean
	cd mlx && make clean

fclean : clean
	rm -rf $(NAME)
	cd libft && make fclean
	cd mlx && make clean

re: fclean all

.PHONY: all bonus clean fclean re
