/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** compare_hole.c
*/

#include <ncurses.h>
#include <string.h>
#include "my.h"
#include "sokoban.h"

void find_hole(sokoban_t *data, int i, int j)
{
    if (data->tab_copy[i][j] == 'O') {
        if (data->tab[i][j] == ' ') {
            data->tab[i][j] = 'O';
        }
    }
}

void compare_hole(sokoban_t *data)
{
    int i = 0;
    int j = 0;

    while (i != data->size_of_tab) {
        while (data->tab_copy[i][j] != '\0') {
            find_hole(data, i, j);
            j++;
        }
        j = 0;
        i++;
    }
}
