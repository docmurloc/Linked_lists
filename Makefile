##
## EPITECH PROJECT, 2019
## test_chaine_list
## File description:
## makfile
##

CC = gcc

CPPFLAGS = -Wall -Wextra -Werror -I ./include

LIBS = -lcriterion

SRC =	./src/linked_list_change.c \
		./src/linked_list_delete.c \
		./src/linked_list_add_data.c \
		./src/linked_list_add.c \
		./src/linked_list_connect.c \
		./src/linked_list_create.c \
		./src/linked_list_get_rank_element.c \
		./src/linked_list_get.c \
		./src/linked_list_init.c \
		./src/linked_list_look_for.c \
		./src/linked_list_macro_func.c \

TEST_FILE = ./test_unit/test.c \

NAME = test
NAME_LIB = libLinked_list.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) $(TEST_FILE) -o $(NAME) $(LIBS)

lib: $(OBJ)
	ar rcs $(NAME_LIB) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_LIB)
re: fclean all
