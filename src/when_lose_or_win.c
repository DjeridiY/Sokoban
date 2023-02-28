/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** when_lose.c
*/

#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include "my.h"
#include "sokoban.h"
#include <stdlib.h>

int condition_win_or_loose(sokoban_t *data)
{
    if (condition_victory(data) == 1) {
        return 10;
    }
    if (condition_lose(data) == 1) {
        return 1;
    }
    return 0;
}
