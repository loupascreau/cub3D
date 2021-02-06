SRCS		=	main.c \
				./parse/parse_file.c \
				./parse/colors.c \
				./parse/textures.c \
				./parse/check_digit.c \
				./parse/parse_map.c \
				./parse/check_map.c \
				./parse/coordinates.c \
				./parse/convert/ft_convert_base.c \
				./parse/convert/ft_convert_base2.c \
				./get_next_line/get_next_line.c \
				./get_next_line/get_next_line_utils.c \
				./utils/utils.c \
				./utils/utils_bis.c \
				./utils/ft_split.c \
				./raycast/setup_parse.c \
				./raycast/raycasting.c \
				./raycast/pixel_put.c \
				./raycast/textures.c \
				./errors/error.c \
				./engine/engine.c \

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
