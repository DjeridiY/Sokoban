/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** free_function.c
*/

#include "my.h"
#include <stdlib.h>

void free_function(char **tab, int size)
{
    for (int o = 0; o != size; o++) {
        free(tab[o]);
    }
    free(tab);
}
