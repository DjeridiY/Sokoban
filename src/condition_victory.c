/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** condition_victory.c
*/

#include <ncurses.h>
#include <string.h>
#include "my.h"
#include "sokoban.h"

void all_hole_are_fill(sokoban_t *data, int i, int j)
{
    if (data->tab_copy[i][j] == 'O') {
        if (data->tab[i][j] == 'X') {
            data->hole_fill += 1;
        }
    }
}

int condition_victory(sokoban_t *data)
{
    int i = 0;
    int j = 0;

    data->hole_fill = 0;
    while (i != data->size_of_tab) {
        while (data->tab_copy[i][j] != '\0') {
            all_hole_are_fill(data, i, j);
            j++;
        }
        j = 0;
        i++;
    }
    if (data->hole_fill == data->hole) {
        return 1;
    } else {
        data->hole_fill = 0;
    }
    return 0;
}
