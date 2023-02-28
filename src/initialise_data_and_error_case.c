/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** initialise_data_and_error_case.c
*/

#include <ncurses.h>
#include <string.h>
#include "my.h"
#include "sokoban.h"
#include <stdlib.h>

int initialise_data_and_error_case(sokoban_t *data, char **av)
{
    if (file_to_tab(av[1], data) == 84) {
        return 84;
    }
    if (how_many_hole_and_case(data) == 84) {
        return 84;
    }
    return 0;
}
