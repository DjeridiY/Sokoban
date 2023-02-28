/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** already_lost.c
*/

#include <ncurses.h>
#include <string.h>
#include "my.h"
#include "sokoban.h"
#include <stdlib.h>

int already_lost(sokoban_t *data)
{
    if (condition_lose(data) == 1) {
        my_printf("%s\n", "the boxes are already blocked or inexistant");
        return 84;
    }
    return 0;
}
