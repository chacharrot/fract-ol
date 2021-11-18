NAME		=	fractol
OS			= $(shell uname)

FILES_C		=	\
				draw.c \
				main.c \
				function.c \
				control.c \
				type.c

FILES_B		=	\
				draw.c \
				main.c \
				function.c \
				control.c \
				type.c

DIR_C		=	./src

SRCS		=	$(addprefix $(DIR_C)/, $(FILES_C))
SRCS_B		=	$(addprefix $(DIR_C)/, $(FILES_B))

OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)

CC			=	gcc
C_FLG		=	-Wall -Wextra -Werror

ifeq ($(OS), Linux)
	MLX_FLG		=	-Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd
else
	MLX_FLG	= -Lminilibx_opengl_20191021 -l mlx -framework OpenGL -framework AppKit
endif

.SILENT		:

$(NAME)		:	mandatory

all			:	$(NAME)

bonus		:	bonus_part

.c.o		:
		echo -n "\tCompiling $<\n"
		$(CC) -c $< -o $(<:.c=.o)

mandatory	: $(OBJS)
	$(CC) $(C_FLG) -o $(NAME) $(OBJS) $(MLX_FLG)

bonus_part	: $(OBJS_B)
	$(CC) $(C_FLG) -o $(NAME) $(OBJS_B) $(MLX_FLG)

clean		:
		rm -f $(OBJS)
		rm -f $(OBJS_B)

fclean		:	clean
		rm -f $(NAME)

aclean		:	all clean

re			:	fclean all

.PHONY		:	all clean fclean aclean re