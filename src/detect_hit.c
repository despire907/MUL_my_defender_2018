/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** turret_function
*/

#include "music.h"

void neg_life(game_t *game, gui_t *gui)
{
    mob_t *begin = game->mob_list;
    turret_t *second_begin = gui->turret;

    while (gui->turret != NULL) {
        while (game->mob_list != NULL) {
            if (game->mob_list->position.x == gui->turret->hit->position.x
                && game->mob_list->position.y == gui->turret->hit->position.y) {
                game->mob_list->life = game->mob_list->life - 1;
            }
            game->mob_list = game->mob_list->next;
        }
        game->mob_list = begin;
        gui->turret = gui->turret->next;
    }
    gui->turret = second_begin;
}

void hit_initialize_value(turret_t *turret, int hauteur, int fin, float taille)
{
    turret->hit->taille_sprite = taille;
    turret->hit->fin_sprite = fin;
    turret->hit->hauteur_sprite = hauteur;
}

void hit_data(gui_t *gui)
{
    turret_t *begin = gui->turret;

    hit_initialize_value(gui->turret, 118, 218, 109.00);
    gui->turret = gui->turret->next;
    hit_initialize_value(gui->turret, 104, 212, 106.00);
    gui->turret = gui->turret->next;
    hit_initialize_value(gui->turret, 119, 244, 122.00);
    gui->turret = gui->turret->next;
    hit_initialize_value(gui->turret, 118, 218, 109.00);

    gui->turret = begin;
}

void hit_touch(gui_t *gui, game_t *game)
{
    turret_t *begin = gui->turret;

    while (gui->turret != NULL) {
        if (gui->turret->hit->pos == 1) {
            hit_sound(game);
            rec_mouvement_hit(&gui->turret->hit->rect, gui);
            sfSprite_setTextureRect(gui->turret->hit->hit,
                    gui->turret->hit->rect);
        }
        gui->turret = gui->turret->next;
    }
    gui->turret = begin;
}

void sub_function(game_t *game)
{
    game->mob_list->position.x = -110;
    game->mob_list->life = 3;
    sfSprite_setPosition(game->mob_list->walk_sprite, game->mob_list->position);
}