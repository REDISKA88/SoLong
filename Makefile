SRCS		=	ft_checks.c \
                ft_errors.c \
                game.c \
                keystrokes.c \
                load_xpm.c \
                main.c \
                map_func.c \
                put_image.c \
                utils.c	\
                ./gnl/get_next_line.c \
				./gnl/get_next_line_utils.c

OBJS 		= ${SRCS:.c=.o}


MLX			= mlx
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long
FLAGS		=  -lmlx -framework OpenGL -framework AppKit mlx/libmlx.a

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			$(CC) $(OBJS) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re