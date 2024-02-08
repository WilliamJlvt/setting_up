/*
** EPITECH PROJECT, 2023
** my strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int index = 0;

    while (str[index] != '\0') {
        index++;
    }
    return index;
}
