##
## EPITECH PROJECT, 2023
## My main file
## File description:
## main.c
##

TARGET	=	setting_up
CC		=	gcc
OBJS	=	${SRCS:.c=.o}

SRCS 	=	src/setting_up.c			src/generator.c					\
		src/file_parser.c			src/algorithm.c					\
		lib/my/my_strlen.c			lib/my/my_getnbr.c				\

${TARGET}: ${OBJS}
	${CC} -o ${TARGET} ${OBJS} -I include
re: fclean all

all: ${TARGET}

clean:
	rm -fr ${OBJS}

fclean: clean
	rm -fr ${TARGET}
