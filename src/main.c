/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** main function
*/

#include "game.h"

sfRenderWindow *window_create(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1026, 728, 32};

    window = sfRenderWindow_create(mode, "my_defender", sfResize | sfClose,
            NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return window;
}

int main_manager(sfRenderWindow *window, char *name, int check, int i)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(window)) {
        if (i == 2) {
            if (menu_start(window, event) == 84)
                return 0;
        }
        i = 2;
        check = game_start(window, event, name);
        if (check == 84)
            return 0;
        else if (check == 1)
            i = 0;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int i = 2;
    int check = 0;
    sfRenderWindow *window = window_create();

    if (!window || argc > 2)
        return (84);
    main_manager(window, argv[1], check, i);
    sfRenderWindow_destroy(window);
    return (0);
}