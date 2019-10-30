/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** sound function
*/

#include "game.h"

void init_sound(game_t *game)
{
    game->hit = sfMusic_createFromFile("music/hit.ogg");
    game->die = sfMusic_createFromFile("music/die.ogg");
}

void hit_sound(game_t *game)
{
    sfMusic_play(game->hit);
}

void die_sound(game_t *game)
{
    sfMusic_play(game->die);
}

void destroy_sound(game_t *game)
{
    sfMusic_destroy(game->hit);
    sfMusic_destroy(game->die);
}