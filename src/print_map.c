/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** print_map.c
*/

#include <ncurses.h>
#include <string.h>
#include "my.h"
#include "sokoban.h"

void print_map(sokoban_t *data)
{
    clear();
    for (int i = 0; i != data->size_of_tab; i++)
        mvprintw(0 + i, 0, data->tab[i]);
    refresh();
}
