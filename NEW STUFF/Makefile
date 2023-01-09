SRCS		= main.c misc.c pusher.c pusher2.c checker.c

OBJS		= $(SRCS:.c=.o)

NAME		= push_swap

CC			= gcc

FLAGS		= -Wall -Werror -Wextra

RM			= rm -rf

%.c			= %.o 

all:		${NAME}

${NAME}:	${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:		
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			clean all

.PHONY:		all clean fclean re