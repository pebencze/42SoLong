NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
MINILBX_FLAGS = -L -lmlx -lXext -lX11 -lbsd
MINILIBX = minilibx-linux/libmlx.a
LIBFT = Libft/libft.a
SRCS = 	srcs/create_window.c\
		srcs/flood_fill.c\
		srcs/check_map.c\
		srcs/save_map.c\
		srcs/ft_exit.c\
		srcs/events.c\
		srcs/utils.c\
		srcs/main.c\

all: minilibx libft $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(CFLAGS) $(SRCS) $(MINILIBX) $(MINILBX_FLAGS) $(LIBFT)

minilibx:
	make -C minilibx-linux

libft:
	make -C Libft

clean:
	rm -f Libft/*.o

fclean: clean
	rm -f Libft/libft.a
	rm -f $(NAME)
	rm -f minilibx-linux/libmlx.a
	rm -f minilibx-linux/libmlx_Linux.a

re: fclean all

.PHONY: all clean fclean re minilibx libft
