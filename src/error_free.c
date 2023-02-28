/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** error_free.c
*/

#include <ncurses.h>
#include <string.h>
#include "my.h"
#include <stdlib.h>
#include "sokoban.h"

void error_free(sokoban_t *data)
{
    free_function(data->tab, data->size_of_tab);
    free_function(data->tab_copy, data->size_of_tab);
    free(data);
    endwin();
    exit (84);
}
