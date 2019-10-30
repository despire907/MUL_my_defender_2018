/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** temp function
*/

#include "game.h"

sfVector2f check_mob_position(mob_t *mob)
{
    int y_stock = mob->position.y;
    int x_stock = mob->position.x;
    return (init_vector(x_stock, y_stock));
}

void bullet_placer(gui_t *gui)
{
    turret_t *begin = gui->turret;

    while (gui->turret != NULL) {
        if (gui->turret->rect.left >= 325) {
            gui->turret->hit->rect.left = 0;
            gui->turret->hit->rect.top = 0;
            sfSprite_setTextureRect(gui->turret->hit->hit,
                    gui->turret->hit->rect);
            gui->turret->hit->pos = 2;
        }
        gui->turret = gui->turret->next;
    }
    gui->turret = begin;
}

void bullet_scale(turret_t *turret)
{
    turret_t *begin = turret;
    sfVector2f scale = {0.37, 0.37};

    while (turret != NULL) {
        sfSprite_setScale(turret->hit->hit, scale);
        turret = turret->next;
    }
    turret = begin;
}

void bullet_display(gui_t *gui, sfRenderWindow *window)
{
    turret_t *begin = gui->turret;

    while (gui->turret != NULL) {
        if (gui->turret->hit->pos >= 1) {
            sfRenderWindow_drawSprite(window, gui->turret->hit->hit, NULL);
        }
        gui->turret = gui->turret->next;
    }
    gui->turret = begin;
}

void hit_deplacement(turret_t *turret, mob_t *mob, gui_t *gui, game_t *game)
{
    turret_t *begin = turret;
    mob_t *second_begin = mob;
    sfVector2f dest;
    int i = 0;

    while (turret != NULL) {
        while (mob != NULL) {
            dest = check_mob_position(mob);
            if (turret->hit->pos == 2) {
                turret->hit->destination = dest;
                hit_rect(turret, gui, game);
                i = i + 1;
            }
            mob = mob->next;
        }
        mob = second_begin;
        turret = turret->next;
    }
    turret = begin;
    hit_touch(gui, game);
}