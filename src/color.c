/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "game.h"

void chang_color(sfSprite *sprite, sfColor color)
{
    sfSprite_setColor(sprite, color);
}

void change_life(game_t *game)
{
    mob_t *begin = game->mob_list;

    while (game->mob_list != NULL) {
        if (game->mob_list->life == 3) {
            chang_color(game->mob_list->walk_sprite, sfWhite);
            chang_color(game->mob_list->attack_sprite, sfWhite);
        } else if (game->mob_list->life == 2) {
            chang_color(game->mob_list->walk_sprite, sfYellow);
            chang_color(game->mob_list->attack_sprite, sfYellow);
        } else if (game->mob_list->life == 1) {
            chang_color(game->mob_list->walk_sprite, sfRed);
            chang_color(game->mob_list->attack_sprite, sfRed);
        }
        game->mob_list = game->mob_list->next;
    }
    game->mob_list = begin;
}