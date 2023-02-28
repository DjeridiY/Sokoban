/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** ncurse_function.c
*/

#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "my.h"
#include "sokoban.h"
#include <fcntl.h>

void ncurse_function(void)
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
}
