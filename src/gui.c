/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** gui function
*/

#include "game.h"

sfVector2f init_vector(int x, int y)
{
    sfVector2f new;

    new.x = x;
    new.y = y;

    return (new);
}

gui_t *init_gui(void)
{
    gui_t *new = malloc(sizeof(gui_t));

    new->music = sfMusic_createFromFile("music/music.ogg");
    new->gui_button = gui_button_initialiser();
    new->turret = turret_initialiser();
    new->button = button_initialiser();
    return (new);
}

int gui_display(sfRenderWindow *window, gui_t *gui)
{
    gui_button_t *begin = gui->gui_button;

    while (gui->gui_button != NULL) {
        sfRenderWindow_drawSprite(window, gui->gui_button->sprite, NULL);
        gui->gui_button = gui->gui_button->next;
    }
    gui->gui_button = begin;
    return (0);
}

void set_turret_pos(int nb, gui_t *gui)
{
    button_t *begin = gui->button;

    while (gui->button != NULL) {
        if (gui->button->pos == 0)
            gui->button->pos = nb;
        gui->button = gui->button->next;
    }
    gui->button = begin;
}

int gui_check(sfEvent event, gui_t *gui, game_t *game)
{
    button_check(event, gui, game);
    turret_finder(gui, event, gui->wait_event, game);
    if (gui->wait_event != 0) {
        set_turret_pos(1, gui);
    }
    return (0);
}