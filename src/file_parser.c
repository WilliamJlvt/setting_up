/*
** EPITECH PROJECT, 2023
** final
** File description:
** file_parser.c
*/

#include "../include/my_lib.h"
#include "../include/setting_up.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *get_file_content(char *file_name, int *rows, int *cols, int *first_char)
{
    int fd = open(file_name, O_RDONLY);
    struct stat sb;
    char *buffer;

    stat(file_name, &sb);
    buffer = malloc(sizeof(char) * sb.st_size + 1);
    read(fd, buffer, sb.st_size);
    buffer[sb.st_size + 1] = '\0';
    *rows = my_getnbr(buffer);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            *first_char = i + 1;
            break;
        }
    }
    *cols = ((sb.st_size - *first_char) / *rows) - 1;
    return (buffer);
}

square_t *parse_file(char *file_name)
{
    square_t *result = malloc(sizeof(square_t));
    int first_char;
    char *buffer = get_file_content(file_name, &result->rows, &result->cols,
        &first_char);
    char **map = malloc(sizeof(char *) * (result->rows + 1));

    for (int i = 0; i < result->rows; i++) {
        map[i] = malloc(sizeof(char) * (result->cols + 1));
        for (int j = 0; j < result->cols; j++) {
            map[i][j] = buffer[first_char];
            first_char++;
        }
        map[i][result->cols] = '\0';
        first_char++;
    }
    free(buffer);
    result->map = map;
    return result;
}
