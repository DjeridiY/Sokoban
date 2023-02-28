/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** free_function.c
*/

#include "my.h"

void print_tab(char **tab)
{
    int i = 0;

    while (tab[i] != 0) {
        my_printf("%s\n", tab[i]);
        i++;
    }
}
