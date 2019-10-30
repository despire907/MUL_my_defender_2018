/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** game loop function
*/

#include "game.h"

int abs(int n)
{
    if (n < 0)
        return (-n);
    else
        return (n);
}

int dcnt(int n)
{
    int result = 0;
    int begin = 1;

    while (begin == 1 || n != 0) {
        begin = 0;
        n = n / 10;
        result = result + 1;
    }

    return (result);
}

int power10(int n)
{
    int power = 1;

    while (n > 1) {
        power = power * 10;
        n = n - 1;
    }

    return (power);
}

char *int_to_string(int score)
{
    int is_neg = 0, mod, tmp, offset = 0;
    int digit_count = dcnt(abs(score + ((score < -2147483647) ? 1 : 0)));
    char *res = malloc(sizeof(*res) * (digit_count + 1));

    while (digit_count > 0) {
        tmp = score / power10(digit_count);
        mod = tmp % 10;
        mod *= ((is_neg) ? -1 : 1);
        res[(offset++)] = '0' + mod;
        digit_count -= 1;
    }
    res[(offset++)] = 0;
    return (res);
}