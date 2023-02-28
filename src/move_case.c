/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** move_case.c
*/

#include <ncurses.h>
#include <string.h>
#include "my.h"
#include "sokoban.h"
#include <stdlib.h>

int move_case_left(sokoban_t *data)
{
    char temp;

    if (data->tab[data->player_x][data->player_y - 1] == 'X') {
        if ((data->player_y - 2 == (-1))) {
            return 84;
        }
        if (data->tab[data->player_x][data->player_y - 2] == ' ' ) {
            temp = data->tab[data->player_x][data->player_y - 1];
            data->tab[data->player_x][data->player_y - 1] =
            data->tab[data->player_x][data->player_y - 2];
            data->tab[data->player_x][data->player_y - 2] = temp;
        } else {
            temp = data->tab[data->player_x][data->player_y - 2];
            data->tab[data->player_x][data->player_y - 2] =
            data->tab[data->player_x][data->player_y - 1];
            data->tab[data->player_x][data->player_y - 1] = ' ';
        }
    }
    return 0;
}

int move_case_right(sokoban_t *data)
{
    char temp;
    int length = my_strlen(data->tab[data->player_x]);

    if (data->tab[data->player_x][data->player_y + 1] == 'X') {
        if (data->player_y + 2 == length) {
            return 84;
        }
        if (data->tab[data->player_x][data->player_y + 2] == ' ' ) {
            temp = data->tab[data->player_x][data->player_y + 1];
            data->tab[data->player_x][data->player_y + 1] =
            data->tab[data->player_x][data->player_y + 2];
            data->tab[data->player_x][data->player_y + 2] = temp;
        } else {
            temp = data->tab[data->player_x][data->player_y + 2];
            data->tab[data->player_x][data->player_y + 2] =
            data->tab[data->player_x][data->player_y + 1];
            data->tab[data->player_x][data->player_y + 1] = ' ';
        }
    }
    return 0;
}

int move_case_up(sokoban_t *data)
{
    char temp;

    if (data->tab[data->player_x - 1][data->player_y] == 'X') {
        if ((data->player_x - 2 == 0)) {
            return 84;
        }
        if (data->tab[data->player_x - 2][data->player_y] == ' ' ) {
            temp = data->tab[data->player_x - 1][data->player_y];
            data->tab[data->player_x - 1][data->player_y] =
            data->tab[data->player_x - 2][data->player_y];
            data->tab[data->player_x - 2][data->player_y] = temp;
        } else {
            temp = data->tab[data->player_x - 2][data->player_y];
            data->tab[data->player_x - 2][data->player_y] =
            data->tab[data->player_x - 1][data->player_y];
            data->tab[data->player_x - 1][data->player_y] = ' ';
        }
    }
    return 0;
}

int move_case_down(sokoban_t *data)
{
    char temp;

    if (data->tab[data->player_x + 1][data->player_y] == 'X') {
        if ((data->player_x + 1 == data->size_of_tab - 2)) {
            return 84;
        }
        if (data->tab[data->player_x + 2][data->player_y] == ' ' ) {
            temp = data->tab[data->player_x + 1][data->player_y];
            data->tab[data->player_x + 1][data->player_y] =
            data->tab[data->player_x + 2][data->player_y];
            data->tab[data->player_x + 2][data->player_y] = temp;
        } else {
            temp = data->tab[data->player_x + 2][data->player_y];
            data->tab[data->player_x + 2][data->player_y] =
            data->tab[data->player_x + 1][data->player_y];
            data->tab[data->player_x + 1][data->player_y] = ' ';
        }
    }
    return 0;
}
