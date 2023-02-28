/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** reset_game.c
*/


#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "my.h"
#include "sokoban.h"
#include <fcntl.h>

void reset_game(sokoban_t *data, int ac, char **av)
{
    free_function(data->tab, data->size_of_tab);
    free_function(data->tab_copy, data->size_of_tab);
    free(data);
    main(ac, av);
}
