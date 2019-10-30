/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** turret_function
*/

#include "game.h"

void free_gui_button(gui_button_t *gui_button)
{
    gui_button_t *tmp = gui_button;

    while (gui_button != NULL) {
        tmp = gui_button->next;
        sfSprite_destroy(gui_button->sprite);
        free(gui_button);
        gui_button = tmp;
    }
}

void free_hit(hit_t *hit)
{
    sfSprite_destroy(hit->hit);
    free(hit);
}

void free_turret(turret_t *turret)
{
    turret_t *tmp = turret;

    while (turret != NULL) {
        tmp = turret->next;
        sfSprite_destroy(turret->turret);
        free_hit(turret->hit);
        free(turret);
        turret = tmp;
    }
}

void free_button(button_t *button)
{
    button_t *tmp = button;

    while (button != NULL) {
        tmp = button->next;
        sfSprite_destroy(button->button);
        free(button);
        button = tmp;
    }
}

void free_gui(gui_t *gui)
{
    free_gui_button(gui->gui_button);
    free_turret(gui->turret);
    free_button(gui->button);
}