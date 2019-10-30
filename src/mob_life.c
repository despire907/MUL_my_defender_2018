/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** game loop function
*/

#include "game.h"
#include "music.h"

int die_mob_check(mob_t *mob_list, int i, sfRenderWindow *window, game_t *game)
{
    int check = 0;

    if (mob_list->life < 0) {
        if (i % 2 == 0)
            rec_mouvement_run(&game->mob_list->rect, game);
        sfSprite_setTextureRect(mob_list->die_sprite, mob_list->rect);
        die_sound(game);
        sfSprite_setPosition(mob_list->die_sprite, mob_list->position);
        sfRenderWindow_drawSprite(window, mob_list->die_sprite, NULL);
        game->gold = game->gold + 25;
        check = 1;
    }
    return check;
}