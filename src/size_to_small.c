/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** size_to_small.c
*/

#include <ncurses.h>
#include <string.h>
#include "my.h"
#include "sokoban.h"
#include <stdlib.h>

void size_to_small(sokoban_t *data)
{
    if (LINES < data->size_of_tab + 1) {
        clear();
    }
    while (LINES < data->size_of_tab + 1) {
        refresh();
        mvprintw(LINES / 2, COLS / 2 -
        my_strlen("Please enlarge the terminal") / 2,
        "Please enlarge the terminal");
    }
    clear();
}
