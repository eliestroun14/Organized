##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

NAME	= organized

SRC		= ./src/main.c
SRC		+= ./src/add_data/add.c
SRC		+= ./src/disp.c/disp.c
SRC		+= ./src/sort.c/sort.c
SRC		+= ./src/del.c/del.c

LDFLAGS	= -L. -lmy -lshell -I include/ -g -Wall -Wextra

LIB	= make -C lib/

all: $(NAME)
.PHONY:all

$(NAME):
	$(LIB)
	gcc -o $(NAME) $(SRC) $(LDFLAGS)

lib:
	$(LIB)

tests_run:
	cd tests/
	gcc $(TEST_SRC) -o $(TEST_NAME) $(LDFLAGS) $(TESTS_FLAGS)
	./$(TEST_NAME) --always-succeed

clean:
	$(RM) $(OBJS)
.PHONY:clean

fclean: clean
	$(RM) -f $(NAME)
.PHONY:fclean

re: fclean all
.PHONY:re
