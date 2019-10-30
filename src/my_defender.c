/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** game loop function
*/

#include "scorboard.h"
#include "game.h"

void second_set(sfRenderWindow *window, game_t *game)
{
    sfSprite_setPosition(game->mob_list->attack_sprite,
            game->mob_list->position);
    sfSprite_setTextureRect(game->mob_list->attack_sprite,
            game->mob_list->rect);
    sfRenderWindow_drawSprite(window, game->mob_list->attack_sprite, NULL);
}

void set_and_move(game_t *game, sfRenderWindow *window)
{
    sfSprite_setTextureRect(game->mob_list->walk_sprite, game->mob_list->rect);
    sfSprite_move(game->mob_list->walk_sprite, game->mob_list->dep);
    sfRenderWindow_drawSprite(window, game->mob_list->walk_sprite, NULL);
}

void check_position(game_t *game, int i, sfRenderWindow *window)
{
    mob_t *begin = game->mob_list;
    while (game->mob_list != NULL) {
        if (die_mob_check(game->mob_list, i, window, game) == 0) {
            game->mob_list->position = sfSprite_getPosition(game->mob_list->
                    walk_sprite);
            if (game->mob_list->position.x >= game->position.x - 50) {
                if (i % 2 == 0)
                    rec_mouvement_run(&game->mob_list->rect, game);
                second_set(window, game);
            } else {
                if (i % 2 == 0)
                    rec_mouvement_run(&game->mob_list->rect, game);
                set_and_move(game, window);
            }
        } else {
            sub_function(game);
        }
        game->mob_list = game->mob_list->next;
    }
    game->mob_list = begin;
}

void second_loop(game_t *game, sfRenderWindow *window, int i)
{
    init_scale(game);
    sfSprite_setPosition(game->sprite_castle, game->position);
    sfRenderWindow_drawSprite(window, game->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->sprite_castle, NULL);
    check_position(game, i, window);
    change_life(game);
}

int game_loop(sfRenderWindow *window, sfEvent event, game_t *game, gui_t *gui)
{
    int i = 0;

    while (game->end == 0) {
        i++;
        sfRenderWindow_clear(window, sfBlack);
        game->time = sfClock_getElapsedTime(game->clock);
        game->second = game->time.microseconds / 1000.0;
        if (game->second > 2) {
            second_loop(game, window, i);
        }
        gui_display(window, gui);
        plus_drawing(gui, window, i);
        loop_manager(window, event, game, gui);
        sfRenderWindow_display(window);
    }
    add_score(game->player_name, int_to_string(game->gold));
    free_all(game, gui);
    return game->end;
}