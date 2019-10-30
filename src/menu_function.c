/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** menu function
*/

#include "scorboard.h"
#include "game.h"

sfIntRect intrect_create(int top, int left, int width, int height)
{
    sfIntRect new;

    new.top = top;
    new.left = left;
    new.width = width;
    new.height = height;

    return (new);
}

int menu_mouse_click(sfEvent event, sfRenderWindow *window)
{
    sfIntRect play = intrect_create(275, 425, 177, 177);
    sfIntRect close = intrect_create(380, 725, 177, 177);
    sfIntRect htp = intrect_create(500, 425, 177, 177);
    sfIntRect score = intrect_create(380, 120, 177, 177);

    if (sfIntRect_contains(&play, event.mouseButton.x, event.mouseButton.y) ==
    sfTrue)
        return (1);
    if (sfIntRect_contains(&close, event.mouseButton.x, event.mouseButton.y) ==
    sfTrue)
        return (2);
    if (sfIntRect_contains(&htp, event.mouseButton.x, event.mouseButton.y) ==
    sfTrue)
        return (how_to_play(window));
    if (sfIntRect_contains(&score, event.mouseButton.x, event.mouseButton.y)
    == sfTrue)
        return (score_manager(window));
    return (0);
}

int play_button_check(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue)
        return 1;
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
        return 2;
    return 0;
}

int menu_loop(sfRenderWindow *window, sfEvent event, sfSprite *sprite,
        aim_t *my_aim)
{
    int end = 0;

    while (end == 0) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
                return (84);
            }if (event.type == sfEvtMouseButtonPressed)
                end = menu_mouse_click(event, window);
            if (event.type == sfEvtKeyPressed)
                end = play_button_check();
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        aim(my_aim, window);
        sfRenderWindow_display(window);
        if (end == 2)
            return (84);
    }
    return (0);
}

int menu_start(sfRenderWindow *window, sfEvent event)
{
    sfTexture *texture = sfTexture_createFromFile("png/menu_background.png",
            NULL);
    sfSprite *sprite = sfSprite_create();
    aim_t *aim = init_aim();

    sfSprite_setTexture(sprite, texture, sfTrue);

    if (menu_loop(window, event, sprite, aim) == 84)
        return (84);
    return (0);
}