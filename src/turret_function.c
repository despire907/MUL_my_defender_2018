/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** turret_function
*/

#include "game.h"

void turret_check(sfEvent event, gui_t *gui)
{
    button_t *begin = gui->button;

    while (gui->button != NULL) {
        if (check_click(gui->button->rect, event) == 1) {
            gui->button->pos = 2;
        }
        gui->button = gui->button->next;
    }
    gui->button = begin;
}

void init_scale_turret(gui_t *gui)
{
    button_t *begin = gui->button;

    while (gui->button != NULL) {
        sfSprite_setPosition(gui->button->button, gui->button->position);
        gui->button = gui->button->next;
    }
    gui->button = begin;
}

void reset_drawing(gui_t *gui)
{
    button_t *begin = gui->button;

    while (gui->button != NULL) {
        if (gui->button->pos == 1) {
            gui->button->pos = 0;
        }
        gui->button = gui->button->next;
    }
    gui->button = begin;
}

void turret_drawing(gui_t *gui, sfRenderWindow *window, int i)
{
    turret_t *begin = gui->turret;

    while (gui->turret != NULL){
        if (gui->turret->pos == 1 || gui->turret->pos == 2) {
            if (i % 3 == 0)
                rec_mouvement_turret(&gui->turret->rect, gui);
            sfSprite_setTextureRect(gui->turret->turret, gui->turret->rect);
            sfRenderWindow_drawSprite(window, gui->turret->turret, NULL);
        }
        gui->turret = gui->turret->next;
    }
    gui->turret = begin;
    bullet_display(gui, window);
}

void plus_drawing(gui_t *gui, sfRenderWindow *window, int i)
{
    button_t *begin = gui->button;

    while (gui->button != NULL){
        if (gui->button->pos == 1) {
            sfRenderWindow_drawSprite(window, gui->button->button, NULL);
        }
        gui->button = gui->button->next;
    }
    gui->button = begin;
    turret_drawing(gui, window, i);
}