/*
** EPITECH PROJECT, 2023
** final
** File description:
** algorithm.c
*/

#include "../include/setting_up.h"

int is_valid(char c)
{
    return c == '.';
}

int check_square_side(square_t *square, const int y, const int x, int size)
{
    char **map = square->map;
    int current_y = y;
    int current_x = x + size - 1;

    if (current_x >= square->cols) {
        return 0;
    }
    while (current_y < (y + size)) {
        if (current_y >= square->rows || !is_valid(map[current_y][current_x]))
            return 0;
        current_y++;
    }
    current_y--;
    while (current_x >= x) {
        if (!is_valid(map[current_y][current_x]))
            return 0;
        current_x--;
    }
    return 1;
}

int get_higher_square(square_t *square, const int y, const int x)
{
    int size = 1;

    while (check_square_side(square, y, x, size)) {
        size++;
    }
    return size - 1;
}
