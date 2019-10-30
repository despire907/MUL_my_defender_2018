/*
** EPITECH PROJECT, 2019
** CPE_duostumper_8_2018
** File description:
** str_c_dup function
*/

#include <stdlib.h>
#include "game.h"

int my_str_c_len(char *str, char c)
{
    int count = 0;

    if (str == NULL)
        return (0);
    while (str[count] != c && str[count] != '\0') {
        count = count + 1;
    }
    return (count);
}

char *my_str_c_dup(char *src, char *second_src)
{
    int count = 0;
    int second_count = 0;
    char *final;

    final = malloc(sizeof(char) * my_strlen(src) + my_strlen(second_src) + 1);
    if (final == NULL)
        return NULL;
    if (my_str_c_len(src, '\0') != 0) {
        while (src[count] != '\0') {
            final[count] = src[count];
            count = count + 1;
        }
    }
    while (second_count != my_str_c_len(second_src, '\0')) {
        final[count] = second_src[second_count];
        count = count + 1;
        second_count = second_count + 1;
    }
    final[count] = '\0';
    return (final);
}

