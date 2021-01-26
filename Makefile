SRCS		=	main.c \
				utils.c \
				parse_file.c \
				colors.c \
				textures.c \
				parse_map.c \
				check_map.c \
				./get_next_line/get_next_line.c \
				./get_next_line/get_next_line_utils.c \
				coordinates.c \

OBJS		=	${SRCS:.c=.o}

NAME		=	cub3D

MLX_PATH	=	./minilibx-linux/
MLX_NAME	=	$(MLX_PATH)libmlx.a

INC			=	./includes/

CC			=	clang -Wall -Wextra -Werror 
RM			=	rm -f

CFLAGS		=	-lm -lmlx -lXext -lX11

all:		${NAME}

.c.o:	
			${CC} -I${INC} -I${MLX_PATH} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			make -C ${MLX_PATH}
			${CC} ${OBJS} ${MLX_NAME} -L${MLX_PATH} -I${INC} -I${MLX_PATH} ${CFLAGS} -o ${NAME}

clean:		
			make clean -C ${MLX_PATH}
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
