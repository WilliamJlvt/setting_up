/*
** EPITECH PROJECT, 2023
** final
** File description:
** generator.c
*/

#include "../include/setting_up.h"
#include "../include/my_lib.h"

square_t *generate_map(int size, char *pattern)
{
    char **map = malloc(sizeof(char *) * (size + 1));
    int pattern_size = my_strlen(pattern);
    int pattern_index = 0;
    square_t *result = malloc(sizeof(square_t));

    for (int i = 0; i < size; i++) {
        map[i] = malloc(sizeof(char) * (size + 1));
        for (int j = 0; j < size; j++) {
            map[i][j] = pattern[pattern_index];
            pattern_index = (pattern_index + 1) % pattern_size;
        }
        map[i][size] = '\0';
    }
    map[size] = NULL;
    result->map = map;
    result->rows = size;
    result->cols = size;
    return result;
}

void print_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        write(1, map[i], my_strlen(map[i]));
        write(1, "\n", 1);
    }
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

void set_square(square_t *square, int y, int x, int size)
{
    for (int i = y; i < (y + size); i++) {
        for (int j = x; j < (x + size); j++) {
            square->map[i][j] = 'x';
        }
    }
}
