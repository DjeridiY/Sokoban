/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** get_coord_player.c
*/

#include <ncurses.h>
#include <string.h>
#include "my.h"
#include "sokoban.h"
#include <stdlib.h>

int search_player(sokoban_t *data, int i, int j)
{
    int length = my_strlen(data->tab[i]);

    if (data->tab[i][j] == 'P') {
        if ((i - 1 < (-1)) || ((i + 1) > data->size_of_tab - 1) ||
        (j + 1 == length + 1) || (j - 1 < (-1))) {
            return 84;
        }
        data->player_x = i;
        data->player_y = j;
    }
    return 0;
}

int analyse_line(sokoban_t *data, int i)
{
    int j = 0;

    while (data->tab[i][j] != '\0')  {
        if (search_player(data, i, j) == 84) {
            return 84;
        }
        j++;
    }
    return 0;
}

int get_coord_of_player(sokoban_t *data)
{
    int i = 0;
    int recup = 0;

    while (i != data->size_of_tab) {
        if (analyse_line(data, i) == 84) {
            return 84;
        }
        i++;
    }
    return recup;
}
