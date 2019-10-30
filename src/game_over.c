/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** menu function
*/

#include "game.h"

int game_over_mouse_clic(sfEvent event)
{
    sfIntRect replay = intrect_create(280, 419, 190, 199);
    sfIntRect close = intrect_create(432, 677, 177, 177);
    sfIntRect play = intrect_create(433, 162, 177, 177);

    if (sfIntRect_contains(&play, event.mouseButton.x, event.mouseButton.y)
    == sfTrue)
        return 1;
    if (sfIntRect_contains(&close, event.mouseButton.x, event.mouseButton.y)
    == sfTrue)
        return 2;
    if (sfIntRect_contains(&replay, event.mouseButton.x, event.mouseButton.y)
    == sfTrue)
        return 3;
    return 0;
}

int game_over_menu(sfRenderWindow *window, sfEvent event, sfSprite *sprite,
        aim_t *my_aim)
{
    int end = 0;

    while (end == 0) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
                return 84;
            } else if (event.type == sfEvtMouseButtonPressed)
                end = game_over_mouse_clic(event);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        aim(my_aim, window);
        sfRenderWindow_display(window);
        if (end == 2)
            return 84;
        else if (end == 3)
            return 1;
    }
    return 0;
}

int game_over_start(sfRenderWindow *window, sfEvent event)
{
    sfTexture *texture = sfTexture_createFromFile("png/button/game_over.png",
            NULL);
    sfSprite *sprite = sfSprite_create();
    aim_t *aim = init_aim();
    sfSprite_setTexture(sprite, texture, sfTrue);
    int check = game_over_menu(window, event, sprite, aim);

    if (check == 84)
        return 84;
    else if (check == 1)
        return 1;
    return 0;
}