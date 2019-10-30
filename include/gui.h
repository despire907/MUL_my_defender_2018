/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** gui macros
*/

#include <SFML/Graphics.h>
#include "placer_turret.h"

#ifndef GUI_H_
#define GUI_H_

typedef struct gui_button {
    int pos;
    int key;
    int cost;
    sfIntRect rect;
    sfIntRect clickable;
    sfVector2f position;
    sfSprite *sprite;
    struct gui_button *next;
}gui_button_t;

typedef struct gui
{
    int wait_event;
    sfMusic *music;
    gui_button_t *gui_button;
    turret_t *turret;
    button_t *button;
    hit_t *hit;
}gui_t;

#endif