/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** how to play function
*/

#include <stdio.h>
#include "game.h"

int how_to_play_loop(sfSprite *sprite, sfRenderWindow *window)
{
    sfBool end = sfTrue;
    sfEvent event;

    while (end == sfTrue) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
                return (2);
            } else if (event.type == sfEvtKeyPressed &&
            event.key.code == sfKeyEscape)
                end = sfFalse;
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    return (0);
}

int how_to_play(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("png/howtoplay.png", NULL);
    sfSprite *sprite = sfSprite_create();
    int check = 0;

    sfSprite_setTexture(sprite, texture, sfTrue);
    check = how_to_play_loop(sprite, window);
    return (check);
}
