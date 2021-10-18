NAME =	so_long


SRCS = 		main.c
				

OBJS =	$(SRCS:.c=.o)

LIBS	= -lm -lmlx -lXext -lX11

MLX_DIR	= mlx

CC =	gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

RM = 	rm -f

INCS	=	includes/

HEADERS	=	-I $(INCS) -I $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -L $(MLX_DIR) $^ -o $(NAME) $(LIBS)

all : $(NAME)

clean :
		make -C $(MLX_DIR) clean
		$(RM) $(OBJS)

fclean : clean
		rm -f $(MLX_DIR)/libmlx_Linux.a
		$(RM) $(NAME)

re : fclean all

.PHONY :
		all clean fclean re