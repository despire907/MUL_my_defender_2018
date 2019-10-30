/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** game loop function
*/

#include "game.h"

void rec_mouvement_run(sfIntRect *rec, game_t *game)
{
    rec->left = rec->left + game->mob_list->def_sprite->taille_sprite;
    if (rec->left >= game->mob_list->def_sprite->fin_sprite) {
        rec->left = 0;
        rec->top = rec->top + game->mob_list->def_sprite->hauteur_sprite;
        if (rec->top >= game->mob_list->def_sprite->hauteur_sprite * 5) {
            rec->top = 0;
            if (game->mob_list->position.x >= game->position.x - 50) {
                game->life_castle = game->life_castle - 1;
            }
        }
    }
}

void rec_mouvement_turret(sfIntRect *rec, gui_t *gui)
{
    if (gui->turret->pos == 1)
        rec->left = rec->left + gui->turret->taille_sprite;
    bullet_placer(gui);
    if (rec->left >= gui->turret->fin_sprite) {
        rec->left = 0;
        gui->turret->pos = 2;
    }
}

void rect_moover(int left, sfIntRect *rect)
{
    rect->left = left;
}

void hit_rect(turret_t *turret, gui_t *gui, game_t *game)
{
    if (turret->hit->position.x <= turret->hit->destination.x)
        turret->hit->position.y = turret->hit->position.y + 10;
    else {
        turret->hit->position.x = turret->hit->position.x - 4;
        if (turret->hit->position.y < 200)
            turret->hit->position.y = turret->hit->position.y - 4;
    }
    if (turret->hit->position.x < turret->hit->destination.x - 10)
        turret->hit->position.x = turret->hit->position.x + 10;
    if (turret->hit->position.x <= turret->hit->destination.x
        && turret->hit->position.y >= turret->hit->destination.y) {
        turret->hit->position = turret->hit->destination;
        turret->hit->pos = 1;
        neg_life(game, gui);
    }
    sfSprite_setPosition(turret->hit->hit, turret->hit->position);
}

void rec_mouvement_hit(sfIntRect *rec, gui_t *gui)
{
    rec->left = rec->left + gui->turret->hit->taille_sprite;

    if (rec->left >= gui->turret->hit->fin_sprite) {
        rec->left = 0;
        rec->top = rec->top + gui->turret->hit->hauteur_sprite;
    }
    if (rec->top >= (gui->turret->hit->hauteur_sprite * 3)) {
        rec->top = 0;
        rec->left = 0;
        gui->turret->hit->pos = 1;
        gui->turret->pos = 1;
        gui->turret->hit->position = gui->turret->hit->start_position;
    }
}