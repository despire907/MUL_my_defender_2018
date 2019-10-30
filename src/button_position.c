/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button position function
*/

#include "game.h"

void set_button_pos(gui_t *gui)
{
    gui_button_t *begin = gui->gui_button;

    while (gui->gui_button != NULL) {
        if (gui->gui_button->pos == 0)
            rect_moover(0, &gui->gui_button->rect);
        if (gui->gui_button->pos == 1)
            rect_moover(130, &gui->gui_button->rect);
        if (gui->gui_button->pos == 2)
            rect_moover(260, &gui->gui_button->rect);
        if (gui->gui_button->pos == 3)
            rect_moover(260, &gui->gui_button->rect);
        sfSprite_setTextureRect(gui->gui_button->sprite, gui->gui_button->rect);
        gui->gui_button = gui->gui_button->next;
    }
    gui->gui_button = begin;
}

void change_position(gui_t *gui, int key, int compare)
{
    gui_button_t *begin = gui->gui_button;

    while (gui->gui_button != NULL) {
        if (gui->gui_button->pos == compare)
            gui->gui_button->pos = key;
        gui->gui_button = gui->gui_button->next;
    }
    gui->gui_button = begin;
}

void declick_position(gui_t *gui, int key, int compare)
{
    gui_button_t *begin = gui->gui_button;

    while (gui->gui_button != NULL) {
        if (gui->gui_button->pos != compare)
            gui->gui_button->pos = key;
        gui->gui_button = gui->gui_button->next;
    }
    gui->gui_button = begin;
}

void check_check(gui_t *gui, int check)
{
    if (check == 1)
        change_position(gui, 2, 0);
    else if (check == 2) {
        declick_position(gui, 0, 3);
        gui->wait_event = 0;
        reset_drawing(gui);
    }
    set_button_pos(gui);
}

void button_check(sfEvent event, gui_t *gui, game_t *game)
{
    gui_button_t *begin = gui->gui_button;
    int check = 0;

    while (gui->gui_button != NULL) {
        if (sfIntRect_contains(&gui->gui_button->clickable, event.mouseButton.x
                , event.mouseButton.y) == sfTrue && gui->gui_button->pos == 0
                && gui->gui_button->cost <= game->gold){
            gui->gui_button->pos = 1;
            check = 1;
            game->cost = gui->gui_button->cost;
            gui->wait_event = gui->gui_button->key;
        }
        else if (sfIntRect_contains(&gui->gui_button->clickable,
                event.mouseButton.x, event.mouseButton.y) == sfTrue &&
                gui->gui_button->pos == 1)
            check = 2;
        gui->gui_button = gui->gui_button->next;
    }
    gui->gui_button = begin;
    check_check(gui, check);
}
