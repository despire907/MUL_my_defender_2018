/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** init sprite function
*/

#include "game.h"

sfSprite *init_sprite(char *str, sfIntRect rect)
{
    sfTexture *texture = sfTexture_createFromFile(str, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    return sprite;
}