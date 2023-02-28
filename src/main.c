/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-bssokoban-yanis.djeridi
** File description:
** my_popup.c
*/

#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "my.h"
#include "sokoban.h"
#include <fcntl.h>

void exit_the_program(sokoban_t *data)
{
    free_function(data->tab, data->size_of_tab);
    free_function(data->tab_copy, data->size_of_tab);
    free(data);
}

void help_cmd(void)
{
    my_printf("USAGE\n");
    my_printf("     ./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("     map file representing the warehouse map,");
    my_printf(" containing ‘#’ for walls,\n");
    my_printf("         ‘P’ for the player, ‘X’ for boxes");
    my_printf(" and ‘O’ for storage locations.\n");
}

int get_input(sokoban_t *data, int ch, char **av)
{
    if (' ' == ch) {
        free_function(data->tab, data->size_of_tab);
        free_function(data->tab_copy, data->size_of_tab);
        endwin();
        video_game(data, av);
    }
    return 0;
}

int video_game(sokoban_t *data, char **av)
{
    int ch = 0; int value_of_return = 10;

    if (initialise_data_and_error_case(data, av) == 84)
        return 84;
    if (already_lost(data) == 84)
        return 1;
    ncurse_function();
    while ('q' != ch) {
        size_to_small(data);
        if (get_coord_of_player(data) == 84) {
            value_of_return = 84; break;
        } compare_hole(data);
        if (condition_win_or_loose(data) != 0) {
            print_map(data);
            value_of_return = condition_win_or_loose(data); break;
        }
        print_map(data); ch = getch();
        get_input(data, ch, av); motion(data, ch);
    } endwin();
    return value_of_return;
}

int main(int ac, char **av)
{
    sokoban_t *data = malloc(sizeof(sokoban_t));
    int recup = 0;
    *data = (sokoban_t){0};

    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0) {
        help_cmd();
    } else {
        recup = video_game(data, av);
    }
    if (recup == 84) {
        free(data); return 84;
    }
    if (recup == 10) {
        exit_the_program(data); return 0;
    }
    if (recup == 1 || recup == 2) {
        exit_the_program(data); return 1;
    }
}
