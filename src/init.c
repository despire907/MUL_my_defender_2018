/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** game loop function
*/

#include "game.h"
#include "music.h"

void init_scale(game_t *game)
{
    sfVector2f scale = {0.37, 0.37};
    mob_t *begin = game->mob_list;

    sfSprite_setScale(game->sprite_castle, scale);
    while (game->mob_list != NULL) {
        sfSprite_setScale(game->mob_list->attack_sprite, scale);
        sfSprite_setScale(game->mob_list->die_sprite, scale);
        sfSprite_setScale(game->mob_list->walk_sprite, scale);
        game->mob_list = game->mob_list->next;
    }
    game->mob_list = begin;
}

game_t *init_game(void)
{
    game_t *new = malloc(sizeof(game_t));
    init_sound(new);
    new->rect = intrect_create(0, 0, 1026, 728);
    new->rect_castle = intrect_create(0, 0, 1423, 1129);
    new->life_rect = intrect_create(0, 0, 550, 250);
    new->sprite = init_sprite("png/environment_forestbackground3.0.png",
            new->rect);
    new->sprite_castle = init_sprite("png/turrets/Asset 21.png",
            new->rect_castle);
    new->sprite_life = init_sprite("png/button/life_bar_full.png",
            new->life_rect);
    new->position.x = 650;
    new->position.y = 225;
    new->mob_list = list_create();
    new->life_castle = 50;
    new->gold = 100;
    new->clock = sfClock_create();
    new->cost = 0;
    new->end = 0;
    new->aim = init_aim();
    return new;
}

void set_all_position(game_t *game)
{
    mob_t *begin = game->mob_list;

    while (game->mob_list != NULL) {
        sfSprite_setPosition(game->mob_list->walk_sprite,
                game->mob_list->position);
        game->mob_list = game->mob_list->next;
    }
    game->mob_list = begin;
}

int game_start_manager(game_t *game, gui_t *gui)
{
    init_scale_turret(gui);
    set_all_position(game);
    gui->button = button_initialiser();
    gui->wait_event = 0;
    bullet_scale(gui->turret);
    hit_data(gui);
    game->text = text_create(game);
    gold_define(gui->gui_button);
    sfMusic_setLoop(gui->music, sfTrue);
    sfMusic_play(gui->music);
    return (0);
}

int game_start(sfRenderWindow *window, sfEvent event, char *name)
{
    game_t *game = init_game();
    gui_t *gui = init_gui();
    int check = 0;

    game_start_manager(game, gui);
    game->player_name = name;
    check = game_loop(window, event, game, gui);
    if (check == 84) {
        sfMusic_destroy(gui->music);
        return (84);
    } else if (check == 1) {
        sfMusic_destroy(gui->music);
        return 2;
    }
    sfMusic_destroy(gui->music);
    return (0);
}