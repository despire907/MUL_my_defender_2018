/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** pause function
*/

#include <SFML/Graphics/Types.h>
#include "game.h"

int pause_position(sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
        return 1;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyE)
        return 2;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR)
        return 3;
    return (0);
}

int pause_menu(sfRenderWindow *window, sfEvent event)
{
    sfTexture *texture = sfTexture_createFromFile("png/pause.png", NULL);
    sfSprite *sprite = sfSprite_create();
    int check = 0;

    sfSprite_setTexture(sprite, texture, sfTrue);
    while (1) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
                return (2);
            } else if (event.type == sfEvtKeyPressed) {
                check = pause_position(event);
                return (check);
            }
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    return (0);
}