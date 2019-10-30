/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** linked list function
*/

#include "game.h"

void give_and_set(turret_t *turret, button_t *button)
{
    turret->pos = 1;
    turret->position = button->turret_position;
    turret->hit->start_position.x = button->turret_position.x + 8;
    turret->hit->start_position.y = button->turret_position.y - 25;
    turret->hit->position = turret->hit->start_position;
    sfSprite_setPosition(turret->turret, turret->position);
    sfSprite_setPosition(turret->hit->hit, turret->hit->position);
}

void finder(int key, gui_t *gui, button_t *button)
{
    turret_t *begin = gui->turret;

    while (gui->turret != NULL) {
        if (gui->turret->key == key) {
            give_and_set(gui->turret, button);
            gui->wait_event = 0;
            gui->button->pos = 2;
        }
        gui->turret = gui->turret->next;
    }
    gui->turret = begin;
}

void block_and_reset(gui_t *gui)
{
    gui_button_t *begin = gui->gui_button;

    while (gui->gui_button != NULL) {
        if (gui->gui_button->pos == 1 || gui->gui_button->pos == 3)
            gui->gui_button->pos = 3;
        else if (gui->gui_button->pos == 2)
            gui->gui_button->pos = 0;
        gui->gui_button = gui->gui_button->next;
    }
    gui->gui_button = begin;
    set_button_pos(gui);
}

void turret_finder(gui_t *gui, sfEvent event, int key, game_t *game)
{
    button_t *begin = gui->button;
    int check = 0;

    while (gui->button != NULL) {
        if (sfIntRect_contains(&gui->button->rect, event.mouseButton.x,
                event.mouseButton.y) == sfTrue && gui->button->pos == 1) {
            finder(key, gui, gui->button);
            game->gold = game->gold - game->cost;
            check = 1;
        }
        gui->button = gui->button->next;
    }
    gui->button = begin;
    if (check == 1) {
        reset_drawing(gui);
        block_and_reset(gui);
    }
}