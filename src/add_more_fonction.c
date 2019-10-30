/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "game.h"

void check_mouse(gui_t *gui, aim_t *aim)
{
    gui_button_t *begin = gui->gui_button;
    int check = 0;

    while (gui->gui_button != NULL) {
        if (sfIntRect_contains(&gui->gui_button->clickable, aim->mouse.x
                , aim->mouse.y) == sfTrue && gui->gui_button->pos == 0
            && check == 0){
            chang_color(gui->gui_button->sprite, sfRed);
            check = 1;
        } else {
            chang_color(gui->gui_button->sprite, sfWhite);
            check = 0;
        }
        gui->gui_button = gui->gui_button->next;
    }
    gui->gui_button = begin;
}

void loop_manager(sfRenderWindow *window, sfEvent event, game_t *game,
        gui_t *gui)
{
    int check = event_check(window, event, gui, game);

    if (check == 2) {
        game->end = 84;
    } else if (check == 3) {
        game->end = 1;
    }
    dispatche(game, window, event, gui);
    aim(game->aim, window);
    check_mouse(gui, game->aim);
}

int gui_flag_finder(int flag)
{
    static int nb = 1;

    if (flag == 0) {
        nb = nb + 1;
        return (nb - 1);
    } else if (flag == 1)
        nb = 1;
    return (0);
}