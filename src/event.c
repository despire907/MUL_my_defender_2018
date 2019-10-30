/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** event function
*/

#include "pause.h"
#include "game.h"

int event_check(sfRenderWindow *window, sfEvent event, gui_t *gui, game_t *game)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (2);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            gui_check(event, gui, game);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
            return (pause_menu(window, event));
    }
    return (0);
}