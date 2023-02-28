/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-yanis.djeridi
** File description:
** sokoban.h
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

typedef struct sokoban {

    char **tab;
    char **tab_copy;
    int player_x;
    int player_y;
    int hole;
    int number_case;
    int hole_fill;
    int player;
    int case_blocked;
    int nbr_of_hastag;
    int size_of_tab;

} sokoban_t;

int file_to_tab(char *map, sokoban_t *data);
int get_coord_of_player(sokoban_t *data);
int move_down(sokoban_t *data);
int move_up(sokoban_t *data);
int move_right(sokoban_t *data);
int move_left(sokoban_t *data);
int move_case_down(sokoban_t *data);
int move_case_up(sokoban_t *data);
int move_case_left(sokoban_t *data);
int move_case_right(sokoban_t *data);
int motion(sokoban_t *data, int ch);
void compare_hole(sokoban_t *data);
int how_many_hole_and_case(sokoban_t *data);
int condition_victory(sokoban_t *data);
int condition_lose(sokoban_t *data);
void print_map(sokoban_t *data);
int initialise_data_and_error_case(sokoban_t *data, char **av);
int already_lost(sokoban_t *data);
int video_game(sokoban_t *data, char **av);
int case_check(sokoban_t *data, int i, int j);
int case_blocked(sokoban_t *data, int i, int j);
int case_blocked_up_left(sokoban_t *data, int i, int j);
void size_to_small(sokoban_t *data);
int condition_win_or_loose(sokoban_t *data);
void ncurse_function(void);
void reset_game(sokoban_t *data, int ac, char **av);
int main(int ac, char **av);

#endif /* SOKOBAN_H_ */
