/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** linked list function
*/

#include "game.h"

#ifndef MOB_H
#define MOB_H

typedef struct my_name {
    char *name_1;
    char *name_2;
    char *name_3;
}name_t;

typedef struct mob_name {
    name_t *name_mob_1;
    name_t *name_mob_2;
    name_t *name_mob_3;
}mob_name_t;

typedef struct size_sprite {
    int taille_sprite;
    int fin_sprite;
    int hauteur_sprite;
}def_sprite_t;

typedef struct mob {
    int	top;
    int	left;
    int	width;
    int	height;
    int life;
    sfVector2f dep;
    sfVector2f position;
    sfIntRect rect;
    sfSprite *walk_sprite;
    sfSprite *attack_sprite;
    sfSprite *die_sprite;
    def_sprite_t *def_sprite;
    struct mob *next;
}mob_t;

#endif