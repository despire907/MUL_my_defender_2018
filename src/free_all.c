/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** turret_function
*/

#include "game.h"
#include "music.h"

void free_all(game_t *game, gui_t *gui)
{
    destroy_sound(game);
    free_game(game);
    free_gui(gui);
}