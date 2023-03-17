SRCS		= main.c misc.c pusher.c pusher2.c checker.c solver.c

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

#703 786 682 152 744 202 349 232 923 738 229 853 577 935 721 184 301 939 205 428 871 700 265 588 436 290 234 519 491 566 14 689 976 950 286 274 471 714 690 523 803 396 254 253 64 285 73 537 830 942 50 829 197 555 377 576 283 339 957 693 16 717 452 685 854 100 483 271 123 529 237 543 605 474 284 213 563 748 958 642 400 876 962 977 677 971 91 258 498 809 544 344 38 843 606 426 52 807 291 888