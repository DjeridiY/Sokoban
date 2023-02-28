##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SOURCE =	src/

SRC =	$(SOURCE)main.c	\
		$(SOURCE)get_coord_of_player.c	\
		$(SOURCE)move.c	\
		$(SOURCE)move_case.c	\
		$(SOURCE)compare_hole.c	\
		$(SOURCE)how_many_hole_and_case.c	\
		$(SOURCE)condition_victory.c	\
		$(SOURCE)condition_lose.c	\
		$(SOURCE)print_map.c	\
		$(SOURCE)initialise_data_and_error_case.c	\
		$(SOURCE)already_lost.c	\
		$(SOURCE)case_check.c	\
		$(SOURCE)size_to_small.c	\
		$(SOURCE)error_free.c	\
		$(SOURCE)when_lose_or_win.c	\
		$(SOURCE)ncurses_function.c	\
		$(SOURCE)reset_game.c	\
		$(SOURCE)file_to_tab.c

OBJ	=	$(SRC:.c=.o)

NAME	=	sokoban

CFLAGS	=	-I./include/ -lncurses -Wall -Wextra -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(SRC) $(CFLAGS) -L lib/my -lmy
clean :
	make -C lib/my/ clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/my/ fclean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
