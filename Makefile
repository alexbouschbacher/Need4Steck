##
## EPITECH PROJECT, 2018
## Project
## File description:
## Build
##

MAIN_SRC	=	src/main.c

SRC	=	src/utils/my_str_to_word_array.c	\
		src/direction.c	\
		src/alpha.c	\
		src/utils/generator.c	\
		src/utils/checks.c

UT_SRC	=	tests/........

OBJ	=	$(MAIN_SRC:.c=.o) $(SRC:.c=.o)

UT_OBJ	=	$(SRC:.c=.o) $(UT_SRC:.c=.o)

CFLAGS	=	-Werror -Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable -I ./include/

LDFLAGS	=	-lcriterion

NAME	=	ai

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(UT_OBJ)
	find . -name "*.gcda" -type f -delete
	find . -name "*.gcno" -type f -delete

fclean: clean
	rm -f $(NAME)
	rm -f units

re: fclean all

test_run:	$(UT_OBJ)
		gcc -o units $(UT_OBJ) $(LDFLAGS) $(CFLAGS)
		./units
