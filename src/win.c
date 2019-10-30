/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** menu function
*/

#include "game.h"

int win_mouse_clic(sfEvent event)
{
    sfIntRect close = intrect_create(370, 680, 195, 185);
    sfIntRect play = intrect_create(366, 173, 190, 198);

    if (sfIntRect_contains(&play, event.mouseButton.x, event.mouseButton.y)
    == sfTrue)
        return 1;
    if (sfIntRect_contains(&close, event.mouseButton.x, event.mouseButton.y)
    == sfTrue)
        return 2;
    return 0;
}

int win_menu(sfRenderWindow *window, sfEvent event, sfSprite *sprite,
        aim_t *my_aim)
{
    int end = 0;

    while (end == 0) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
                return 84;
            } else if (event.type == sfEvtMouseButtonPressed)
                end = win_mouse_clic(event);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        aim(my_aim, window);
        sfRenderWindow_display(window);
        if (end == 2)
            return 84;
    }
    return 0;
}

int win_start(sfRenderWindow *window, sfEvent event)
{
    sfTexture *texture = sfTexture_createFromFile("png/button/win.png", NULL);
    sfSprite *sprite = sfSprite_create();
    aim_t *aim = init_aim();

    sfSprite_setTexture(sprite, texture, sfTrue);

    if (win_menu(window, event, sprite, aim) == 84)
        return 84;
    return 0;
}

void check_win(sfRenderWindow *window, sfEvent event, game_t *game)
{
    if (game->gold == 1000) {
        if (win_start(window, event) == 84)
            game->end = 84;
        else
            game->end = 2;
    }
}