/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** compare_hole.c
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "sokoban.h"

void hole_and_case(sokoban_t *data, int i, int j)
{
    if (data->tab_copy[i][j] == 'O') {
        data->hole += 1;
    }
    if (data->tab_copy[i][j] == 'X') {
        data->number_case += 1;
    }
    if (data->tab_copy[i][j] == 'P') {
        data->player += 1;
    }
}

int how_many_hole_and_case(sokoban_t *data)
{
    data->player = 0;
    data->hole = 0;
    data->number_case = 0;
    int i = 0;
    int j = 0;

    while (i != data->size_of_tab) {
        while (data->tab_copy[i][j] != '\0') {
            hole_and_case(data, i, j);
            j++;
        }
        j = 0;
        i++;
    }
    if (data->number_case != data->hole || data->player != 1) {
        free_function(data->tab, data->size_of_tab);
        free_function(data->tab_copy, data->size_of_tab);
        return 84;
    }
    return 0;
}
