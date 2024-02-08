/*
** EPITECH PROJECT, 2023
** final
** File description:
** setting_up.c
*/

#include "../include/setting_up.h"
#include "../include/my_lib.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

void find_square(square_t *map, coords_t *coords, int *highest, coords_t *max)
{
    int result_size = get_higher_square(map, coords->i, coords->j);

    if (result_size > *highest) {
        *highest = result_size;
        max->i = coords->i;
        max->j = coords->j;
    }
}

int call_algo(square_t *map)
{
    int highest = 0;
    coords_t *coords = malloc(sizeof(coords_t));
    coords_t max = {0, 0};

    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            coords->i = i;
            coords->j = j;
            find_square(map, coords, &highest, &max);
        }
    }
    set_square(map, max.i, max.j, highest);
    print_map(map->map);
    free(coords);
    free(map);
    return 0;
}

int call_generator(char *argv[])
{
    int size = my_getnbr(argv[1]);

    if (size < 1) {
        write(2, "Error: invalid size\n", 20);
        return 84;
    }
    if (my_strlen(argv[2]) == 0) {
        write(2, "Error: invalid string\n", 22);
        return 84;
    }
    for (int i = 0; argv[2][i] != '\0'; i++) {
        if (argv[2][i] != 'o' && argv[2][i] != '.') {
            write(2, "Error: invalid string\n", 22);
            return 84;
        }
    }
    call_algo(generate_map(my_getnbr(argv[1]), argv[2]));
    return 0;
}

int main(int argc, char *argv[])
{
    struct stat sb;
    int result;

    if (argc == 3) {
        return call_generator(argv);
    }
    if (argc == 2) {
        result = stat(argv[1], &sb);
        if (result == -1) {
            write(2, "Error: invalid file\n", 20);
            return 84;
        }
        return call_algo(parse_file(argv[1]));
    }
    write(2, "Error: invalid arguments\n", 25);
    return 84;
}
