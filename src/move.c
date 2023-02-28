/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** move_down.c
*/

#include <ncurses.h>
#include <string.h>
#include "my.h"
#include "sokoban.h"

int move_left(sokoban_t *data)
{
    char temp;

    if (data->player_y == 0 ||
    data->tab[data->player_x][data->player_y - 1] == '#' )
        return 0;
    if ((data->tab[data->player_x][data->player_y - 1] == 'X') &&
        (data->tab[data->player_x][data->player_y - 2] == '#' ||
        data->tab[data->player_x][data->player_y - 2] == 'X')) {
        return 0;
    }
    if (data->tab[data->player_x][data->player_y - 1] == 'O') {
        data->tab[data->player_x][data->player_y - 1] = ' ';
    }
    if (move_case_left(data) == 84)
        return 84;
    temp = data->tab[data->player_x][data->player_y];
    data->tab[data->player_x][data->player_y] =
    data->tab[data->player_x][data->player_y - 1];
    data->tab[data->player_x][data->player_y - 1] = temp;
    return 0;
}

int move_right(sokoban_t *data)
{
    char temp;

    if ((data->player_y == my_strlen(data->tab[data->player_x]) - 1) ||
    (data->tab[data->player_x][data->player_y + 1] == '#'))
        return 0;
    if ((data->tab[data->player_x][data->player_y + 1] == 'X') &&
        (data->tab[data->player_x][data->player_y + 2] == '#' ||
        data->tab[data->player_x][data->player_y + 2] == 'X')) {
        return 0;
    }
    if (data->tab[data->player_x][data->player_y + 1] == 'O') {
        data->tab[data->player_x][data->player_y + 1] = ' ';
    }
    if (move_case_right(data) == 84)
        return 84;
    temp = data->tab[data->player_x][data->player_y];
    data->tab[data->player_x][data->player_y] =
    data->tab[data->player_x][data->player_y + 1];
    data->tab[data->player_x][data->player_y + 1] = temp;
    return 0;
}

int move_up(sokoban_t *data)
{
    char temp;

    if (data->player_x == 0 ||
        data->tab[data->player_x - 1][data->player_y] == '#')
        return 0;
    if ((data->tab[data->player_x - 1][data->player_y] == 'X') &&
        (data->tab[data->player_x - 2][data->player_y] == '#' ||
        data->tab[data->player_x - 2][data->player_y] == 'X')) {
        return 0;
    }
    if (data->tab[data->player_x - 1][data->player_y] == 'O') {
        data->tab[data->player_x - 1][data->player_y] = ' ';
    }
    if (move_case_up(data) == 84)
        return 84;
    temp = data->tab[data->player_x][data->player_y];
    data->tab[data->player_x][data->player_y] =
    data->tab[data->player_x - 1][data->player_y];
    data->tab[data->player_x - 1][data->player_y] = temp;
    return 0;
}

int move_down(sokoban_t *data)
{
    char temp;

    if ((data->player_x == data->size_of_tab) ||
    (data->tab[data->player_x + 1][data->player_y] == '#'))
        return 0;
    if ((data->tab[data->player_x + 1][data->player_y] == 'X') &&
        (data->tab[data->player_x + 2][data->player_y] == '#' ||
        data->tab[data->player_x + 2][data->player_y] == 'X')) {
        return 0;
    }
    if (data->tab[data->player_x + 1][data->player_y] == 'O') {
        data->tab[data->player_x + 1][data->player_y] = ' ';
    }
    if (move_case_down(data) == 84)
        return 84;
    temp = data->tab[data->player_x][data->player_y];
    data->tab[data->player_x][data->player_y] =
    data->tab[data->player_x + 1][data->player_y];
    data->tab[data->player_x + 1][data->player_y] = temp;
    return 0;
}

int motion(sokoban_t *data, int ch)
{
    if (KEY_DOWN == ch)
        move_down(data);
    if (KEY_RIGHT == ch)
        move_right(data);
    if (KEY_LEFT == ch)
        move_left(data);
    if (KEY_UP == ch)
        move_up(data);
    return 0;
}
