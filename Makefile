SRCS		= main.c misc.c pusher.c pusher2.c pusher3.c checker.c solver.c ft_split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c solver_helper.c misc2.c misc3.c

BSRCS		= bonus.c bonus_helper.c misc.c ft_split.c b_pusher1.c b_pusher2.c b_pusher3.c checker.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c misc2.c

OBJS		= $(SRCS:.c=.o)

BOBJS		= $(BSRCS:.c=.o)

NAME		= push_swap

BNAME		= checker

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf

%.c			= %.o 

all:		${NAME}

bonus:	${BOBJS}
				${CC} ${CFLAGS} ${BOBJS} -o ${BNAME}

${NAME}:	${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:		
				${RM} ${OBJS}
				${RM} ${BOBJS}

fclean:		clean
				${RM} ${NAME} ${BNAME}

re:			clean all

.PHONY:		all clean fclean re

#703 786 682 152 744 202 349 232 923 738 229 853 577 935 721 184 301 939 205 428 871 700 265 588 436 290 234 519 491 566 14 689 976 950 286 274 471 714 690 523 803 396 254 253 64 285 73 537 830 942 50 829 197 555 377 576 283 339 957 693 16 717 452 685 854 100 483 271 123 529 237 543 605 474 284 213 563 748 958 642 400 876 962 977 677 971 91 258 498 809 544 344 38 843 606 426 52 807 291 888