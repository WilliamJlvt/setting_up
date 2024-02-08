/*
** EPITECH PROJECT, 2023
** final
** File description:
** setting_up.h
*/

#ifndef SETTING_UP_H_
    #define SETTING_UP_H_

    #include <stdlib.h>
    #include <unistd.h>

typedef struct square_s {
    char **map;
    int rows;
    int cols;
} square_t;

typedef struct coords_s {
    int i;
    int j;
} coords_t;

square_t *generate_map(int size, char *pattern);
void print_map(char **map);
square_t *parse_file(char *file_name);
int check_square_side(square_t *square, const int y, const int x, int size);
int get_higher_square(square_t *square, const int y, const int x);
void set_square(square_t *square, int y, int x, int size);

#endif
