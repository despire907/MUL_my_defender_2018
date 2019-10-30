/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** linked list function
*/

#ifndef PLACER_TURRET_H
#define PLACER_TURRET_H

typedef struct hit {
    int key;
    int pos;
    float taille_sprite;
    int fin_sprite;
    int hauteur_sprite;
    sfSprite *hit;
    sfVector2f start_position;
    sfVector2f position;
    sfVector2f destination;
    sfIntRect rect;
}hit_t;

typedef struct turret {
    int key;
    int pos;
    float taille_sprite;
    int fin_sprite;
    float mid_sprite;
    sfSprite *turret;
    sfVector2f position;
    sfIntRect rect;
    hit_t *hit;
    struct turret *next;
}turret_t;

typedef struct button {
    sfSprite *button;
    int pos;
    sfIntRect rect;
    sfVector2f position;
    sfVector2f turret_position;
    struct button *next;
}button_t;

turret_t *turret_creater(void);

#endif //PLACER_TURRET_H
