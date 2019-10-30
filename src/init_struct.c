/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** turret_function
*/

#include "game.h"

gui_button_t *gui_button_initialiser(void)
{
    char *name = "png/button/Turrets_button2.0.png";
    gui_button_t *new = new_gui_button(name, intrect_create(0, 0, 130, 130),
            init_vector(20, 585), intrect_create(585, 20, 130, 130));
    gui_button_t *begin = new;
    new->next = new_gui_button(name, intrect_create(130, 0, 130, 130),
            init_vector(170, 575), intrect_create(575, 170, 130, 130));
    new = new->next;
    new->next = new_gui_button(name, intrect_create(260, 0, 130, 130),
            init_vector(320, 575), intrect_create(585, 320, 130, 130));
    new = new->next;
    new->next = new_gui_button(name, intrect_create(390, 0, 130, 130),
            init_vector(465, 570), intrect_create(570, 465, 130, 130));
    new = begin;
    gui_flag_finder(1);
    return new;
}

turret_t *new_turret(char *name, sfIntRect rect, int key, hit_t *hit)
{
    turret_t *new = malloc(sizeof(turret_t));

    new->key = key;
    new->pos = 0;
    new->taille_sprite = 68;
    new->fin_sprite = 675;
    new->mid_sprite = 337.5;
    new->rect = rect;
    new->turret = init_sprite(name, new->rect);
    new->hit = hit;
    new->next = NULL;
    return new;
}

button_t *new_button(char *name, sfIntRect rect, sfVector2f pos,
        sfVector2f turret_pos)
{
    button_t *new = malloc(sizeof(button_t));

    new->pos = 0;
    new->rect = rect;
    new->button = init_sprite(name, intrect_create(0, 0, 50, 49));
    new->position = pos;
    new->turret_position = turret_pos;
    sfSprite_setPosition(new->button, new->position);
    new->next = NULL;

    return new;
}

turret_t *turret_initialiser(void)
{
    char *name = "png/turrets/Turrets5.0.png";
    turret_t *new = new_turret(name, intrect_create(0, 0, 65, 72), 1,
            new_hit("png/effect/40.png", intrect_create(0, 0, 109, 118), 1));
    turret_t *begin = new;
    new->next = new_turret(name, intrect_create(72, 0, 65, 72), 2,
            new_hit("png/effect/29.png", intrect_create(0, 0, 106, 104), 2));
    new = new->next;
    new->next = new_turret(name, intrect_create(158, 0, 65, 92), 3,
            new_hit("png/effect/35.png", intrect_create(0, 0, 122, 119), 3));
    new = new->next;
    new->next = new_turret(name, intrect_create(250, 0, 65, 72), 4,
            new_hit("png/effect/52.png", intrect_create(0, 0, 109, 118), 4));
    new = begin;

    return new;
}

button_t *button_initialiser(void)
{
    char *name = "png/button/button_add_gui.png";
    button_t *new = new_button(name, intrect_create(317, 764, 50, 49),
            init_vector(764, 317), init_vector(755, 265));
    button_t *begin = new;
    new->next = new_button(name, intrect_create(364, 674, 50, 49),
            init_vector(674, 364), init_vector(670, 312));
    new = new->next;
    new->next = new_button(name, intrect_create(475, 780, 50, 49),
            init_vector(780, 475), init_vector(776, 423));
    new = new->next;
    new->next = new_button(name, intrect_create(425, 912, 50, 49),
            init_vector(912, 425), init_vector(908, 373));
    new = begin;
    return new;
}