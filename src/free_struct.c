/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** turret_function
*/

#include "game.h"

void free_aim(aim_t *aim)
{
    sfSprite_destroy(aim->aim);
    free(aim);
}

void free_my_name(name_t *name)
{
    free(name->name_1);
    free(name->name_2);
    free(name->name_3);
    free(name);
}

void free_mob_name(mob_name_t *mob_name)
{
    free_my_name(mob_name->name_mob_1);
    free_my_name(mob_name->name_mob_2);
    free_my_name(mob_name->name_mob_3);
    free(mob_name);
}

void free_mob(mob_t *mob)
{
    mob_t *tmp = mob;

    while (mob != NULL) {
        tmp = mob->next;
        sfSprite_destroy(mob->walk_sprite);
        sfSprite_destroy(mob->attack_sprite);
        sfSprite_destroy(mob->die_sprite);
        free(mob->def_sprite);
        free(mob);
        mob = tmp;
    }
}

void free_game(game_t *game)
{
    sfSprite_destroy(game->sprite);
    sfSprite_destroy(game->sprite_castle);
    sfSprite_destroy(game->sprite_life);
    sfText_destroy(game->text);
    sfClock_destroy(game->clock);
    free_mob(game->mob_list);
    free_aim(game->aim);
}