NAME		=	libftprintf.a

SRCS		=	get_next_line.c get_next_line_utils.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CCFLAGS 	=	-Wall -Wextra -Werror

.c.o:
		$(CC) $(CCFLAGS) -c $< -o $(<:.c=.o) $(LIBS)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
