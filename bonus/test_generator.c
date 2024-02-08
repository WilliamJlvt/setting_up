/*
** EPITECH PROJECT, 2023
** final
** File description:
** test_generator.c
*/

#include <criterion/criterion.h>
#include "../include/setting_up.h"
#include <string.h>

Test(generate_map, test_generate_map)
{
    char **map = generate_map(6, "..o..");
    char *expected[7];

    expected[0] = strdup("..o...\0");
    expected[1] = strdup(".o....\0");
    expected[2] = strdup("o....o\0");
    expected[3] = strdup("....o.\0");
    expected[4] = strdup("...o..\0");
    expected[5] = strdup("..o...\0");
    expected[6] = NULL;

    for (int i = 0; map[i] != NULL; i++) {
        cr_assert_str_eq(map[i], expected[i]);
    }
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}
