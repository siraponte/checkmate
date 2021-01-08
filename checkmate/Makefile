NAME = checkmate

SRCS = checkmate.c chessboard.c check.c move_piece.c error.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

%.o: %.c
	${CC} ${CFLAGS} -c $<

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
