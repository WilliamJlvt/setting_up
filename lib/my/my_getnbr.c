/*
** EPITECH PROJECT, 2023
** final
** File description:
** my_getnbr.c
*/

static int nbr_detector(char c)
{
    if (c >= '0' && c <= '9') {
        return (1);
    }
    return (0);
}

static int operator_detector(char c)
{
    if (c == '-' || c == '+') {
        return (1);
    }
    return (0);
}

static int check_exceed_max_value(int *n, int neg_multiplier)
{
    if (*n > 0 && neg_multiplier < 0) {
        return (0);
    } else if (*n < 0 && neg_multiplier > 0) {
        return (0);
    } else {
        return (*n);
    }
}

static void test_neg(int i, char const *str, int *neg_multiplier)
{
    if (str[i] == '-') {
        *neg_multiplier *= -1;
    }
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    int neg_multiplier = 1;

    while (operator_detector(str[i])) {
        test_neg(i, str, &neg_multiplier);
        i++;
    }
    while (nbr_detector(str[i])) {
        if (nbr_detector(str[i]))
            nbr += str[i] - 48;
        if (nbr_detector(str[i + 1])) {
            nbr = nbr * 10;
        } else {
            nbr = nbr * neg_multiplier;
            return (check_exceed_max_value(&nbr, neg_multiplier));
        }
        i++;
    }
    return (i);
}
