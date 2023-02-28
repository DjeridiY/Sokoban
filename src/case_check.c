/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** case_check.c
*/

#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "my.h"
#include "sokoban.h"
#include <fcntl.h>

int case_blocked_up_left(sokoban_t *data, int i, int j)
{
    if (data->tab[i][j] == 'X') {
        if ((i - 1) < 0) {
            return 84;
        }
        if ((j - 1) < 0) {
            return 84;
        }
        if ((data->tab[i - 1][j] == '#' ||
        data->tab[i - 1][j] == 'X') && (data->tab[i][j - 1] == '#' ||
        data->tab[i][j - 1] == 'X')) {
            return 1;
        }
    }
    return 0;
}

int case_check(sokoban_t *data, int i, int j)
{
    if (case_blocked(data, i, j) == 2)
        data->case_blocked += 1;
    if (case_blocked(data, i, j) == 3)
        data->case_blocked += 1;
    if (case_blocked(data, i, j) == 1)
        data->case_blocked += 1;
    if (case_blocked(data, i, j) == 4)
        data->case_blocked += 1;
    if (case_blocked(data, i, j) == 84)
        return 84;
    if (case_blocked(data, i, j) == 84)
        return 84;
    if (case_blocked(data, i, j) == 84)
        return 84;
    if (case_blocked(data, i, j) == 84)
        return 84;
    return 0;
}
