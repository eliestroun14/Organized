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

SRC		+= ./src/sort.c/merge_split.c

SRC		+= ./src/sort.c/merge_sort_id.c
SRC		+= ./src/sort.c/merge_sort_id_rev.c
SRC		+= ./src/sort.c/merge_sort_type.c
SRC		+= ./src/sort.c/merge_sort_type_rev.c
SRC		+= ./src/sort.c/merge_sort_name.c
SRC		+= ./src/sort.c/merge_sort_name_rev.c

OBJS	= $(SRC:.c=.o)

LDFLAGS	= -L. -lmy -lshell -I include/ -g -Wall -Wextra -pedantic

	GREEN=\033[1;32m
    YELLOW=\033[1;93m
    GREY=\033[2;49m
    ITALIC=\033[3m
    NC=\033[0m

LIB	= make -C lib/

all: $(NAME)

$(NAME): lib
	@ gcc -o $(NAME) $(SRC) $(LDFLAGS)

lib:
	$(LIB)

tests_run:
	cd tests/
	gcc $(TEST_SRC) -o $(TEST_NAME) $(LDFLAGS) $(TESTS_FLAGS)
	./$(TEST_NAME) --always-succeed

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.c.o:
	@ $(CC) -o $(subst .c,.o,$<) -c $< $(CFLAGS) \
        && echo -e "[ ${GREEN}OK${NC} ] ${GREY}$<${NC}" \
        || echo -e "[ ${YELLOW}KO${NC} ] ${ITALIC}$<${NC}"

.PHONY:re fclean all clean tests_run lib .c .o
