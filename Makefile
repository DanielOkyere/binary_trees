# Usage
# make			# compile all binary
# make clean 		# remove all binary

CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
NAME = binary_tree
BETTY = betty

CFLAGS = -Wall -Werror -Wextra -pedantic
DEBUG = ${CFLAGS} -g

.PHONY: all clean oclean fclean re

all: binary_trees.h $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	make oclean

debug:binary_trees.h $(OBJ)
	$(CC) $(DEBUG) $(OBJ) -o binary_debug
	make oclean

clean:
	${RM} *~ $(NAME)

oclean:
	$(RM) $(OBJ)

betty: $(SRC) binary_trees.h
	$(BETTY) $(SRC)

fclean: clean oclean

re: fclean all
