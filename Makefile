SRCS	= main.c srcs/ft_calloc.c srcs/find.c srcs/ft_itoa.c srcs/ending.c srcs/player_settings.c srcs/moves.c srcs/hook.c srcs/ft_strncmp.c srcs/ft_strjoin.c srcs/ft_bzero.c srcs/ft_memset.c srcs/stage_set.c srcs/get_textures.c srcs/error.c srcs/parsing.c srcs/ft_puthexa.c srcs/error2.c srcs/ft_putstrv2.c srcs/ft_putnbr_p.c srcs/get_next_line.c srcs/ft_printf.c srcs/ft_putnbrhexa.c srcs/ft_put_p.c srcs/ft_putnbru2.c srcs/get_next_line_utils.c srcs/ft_putcharv2.c srcs/ft_putnbrv2.c

BONUS	= main.c srcs/ft_calloc.c srcs/find.c srcs/ft_itoa.c srcs/ending.c srcs/player_settings.c srcs/moves.c srcs/hook.c srcs/ft_strncmp.c srcs/ft_strjoin.c srcs/ft_bzero.c srcs/ft_memset.c srcs/stage_set.c srcs/get_textures.c srcs/error.c srcs/parsing.c srcs/ft_puthexa.c srcs/error2.c srcs/ft_putstrv2.c srcs/ft_putnbr_p.c srcs/get_next_line.c srcs/ft_printf.c srcs/ft_putnbrhexa.c srcs/ft_put_p.c srcs/ft_putnbru2.c srcs/get_next_line_utils.c srcs/ft_putcharv2.c srcs/ft_putnbrv2.c

OBJS	=  ${SRCS:.c=.o}

BONUS_OBJS	= ${BONUS:.c=.o}

NAME	= so_long
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -Imlx #-fsanitize=address

all:	${NAME}

bonus: all

${NAME}:	${OBJS}

	${CC} ${CFLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME} ${OBJS}

clean:
		${RM} ${OBJS} ${BONUS_OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus
