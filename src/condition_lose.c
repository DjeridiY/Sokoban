/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** condition_lose.c
*/

#include <ncurses.h>
#include <string.h>
#include "my.h"
#include <stdlib.h>
#include "sokoban.h"

int case_blocked_up_rigth(sokoban_t *data, int i, int j)
{
    int length = my_strlen(data->tab[i]);
    if (data->tab[i][j] == 'X') {
        if ((i - 1) < 0) {
            return 84;
        }
        if ((j + 1) > length) {
            return 84;
        }
        if ((data->tab[i - 1][j] == '#' ||
        data->tab[i - 1][j] == 'X') && (data->tab[i][j + 1] == '#' ||
        data->tab[i][j + 1] == 'X')) {
            return 1;
        }
    }
    return 0;
}

int case_blocked_down_left(sokoban_t *data, int i, int j)
{
    if (data->tab[i][j] == 'X') {
        if ((i - 1) > data->size_of_tab) {
            return 84;
        }
        if ((j - 1) < 0) {
            return 84;
        }
        if ((data->tab[i + 1][j] == '#' || data->tab[i + 1][j] == 'X') &&
        (data->tab[i][j - 1] == '#' || data->tab[i][j - 1] == 'X')) {
            return 1;
        }
    }
    return 0;
}

int case_blocked_down_rigth(sokoban_t *data, int i, int j)
{
    int length = my_strlen(data->tab[i]);
    if (data->tab[i][j] == 'X') {
        if ((i - 1) > data->size_of_tab) {
            return 84;
        }
        if ((j + 1) > length) {
            return 84;
        }
        if ((data->tab[i + 1][j] == '#' || data->tab[i + 1][j] == 'X') &&
            (data->tab[i][j + 1] == '#' || data->tab[i][j + 1] == 'X')) {
                return 1;
        }
    }
    return 0;
}

int case_blocked(sokoban_t *data, int i, int j)
{
    int recup = 0;
    if (case_blocked_down_rigth(data,i, j) == 84) {
        return 84;
    }
    if (case_blocked_down_left(data,i, j) == 84) {
        return 84;
    }
    if (case_blocked_up_rigth(data,i, j) == 84) {
        return 84;
    }
    if (case_blocked_up_left(data,i, j) == 84) {
        return 84;
    }
    recup += case_blocked_down_rigth(data,i, j);
    recup += case_blocked_down_left(data,i, j);
    recup += case_blocked_up_rigth(data,i, j);
    recup += case_blocked_up_left(data,i, j);
    return recup;
}

int condition_lose(sokoban_t *data)
{
    int i = 0;
    int j = 0;
    int recup = 0;
    data->case_blocked = 0;

    while (i != data->size_of_tab) {
        while (data->tab_copy[i][j] != '\0') {
            recup = case_check(data, i, j);
            j++;
        }
        j = 0; i++;
    }
    if (recup == 84) {
        return 84;
    }
    if (data->case_blocked == data->number_case) {
        return 1;
    }
    data->case_blocked = 0;
    return 0;
}
