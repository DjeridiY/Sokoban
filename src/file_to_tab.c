/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-BSQ-yanis.djeridi
** File description:
** main.c
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "my.h"
#include <stdlib.h>
#include <sys/stat.h>
#include "sokoban.h"


int words_count(const char *str, char selecteur)
{
    int count = 0;
    int i = 0;
    int len = 0;
    char last_char;

    len = my_strlen(str);
    if (len > 0) {
        last_char = str[0];
    }
    for (; i <= len; i++) {
        if ((str[i] == selecteur || str[i] == '\0') && last_char != selecteur) {
            count++;
        }
        last_char = str[i];
    }
    return count;
}

void initialize_tab(char *buffer, sokoban_t *data)
{
    data->tab = my_str_to_word_array(buffer, '\n');
    data->tab_copy = my_str_to_word_array(buffer, '\n');
    data->size_of_tab = words_count(buffer, '\n');
}

int error_case_character(char *str)
{
    int i = 0;
    int d = 0;

    while (str[i] != '\0') {
        if (str[i] != '\0' && str[i] != '#' &&
        str[i] != ' ' && str[i] != '\n' && str[i] != 'P'
        && str[i] != 'O' && str[i] != 'X') {
            my_printf("%s\n", "FILE DOESN'T HAVE RIGHT ARGUMENT IN");
            return 84;
        }
        if (str[i] == '#') {
            d++;
        }
        i++;
    }
    if (d == 0) {
        return 84;
    }
    return 0;
}

int file_to_tab(char *map, sokoban_t *data)
{
    struct stat sb; stat(map, &sb);
    int nbr_of_char = sb.st_size;
    int fd = open(map, O_RDONLY); int size = 0;
    char *buffer = malloc(sizeof(char) * (nbr_of_char + 2));

    *buffer = (char){0};
    if (fd == -1)
        return 84;
    size = read(fd, buffer, (nbr_of_char));
    buffer[size] = '\0';
    if (error_case_character(buffer) == 84)
        return 84;
    initialize_tab(buffer, data);
    free(buffer); close(fd);
    if (get_coord_of_player(data) == 84) {
        free_function(data->tab, data->size_of_tab);
        free_function(data->tab_copy, data->size_of_tab);
        return 84;
    } return 0;
}
