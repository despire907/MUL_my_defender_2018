/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** turret_function
*/

#include "game.h"

aim_t *init_aim(void)
{
    aim_t *new = malloc(sizeof(aim_t));

    new->aim = init_sprite("png/button/curseur.png",
            intrect_create(0, 0, 50, 50));

    return new;
}

void aim(aim_t *aim, sfRenderWindow *window)
{
    aim->mouse = sfMouse_getPositionRenderWindow(window);
    aim->coord.x = aim->mouse.x - (20 / 2);
    aim->coord.y = aim->mouse.y - (20 / 2);
    sfSprite_setPosition(aim->aim, aim->coord);
    sfRenderWindow_drawSprite(window, aim->aim, NULL);
}

int check_click(sfIntRect position, sfEvent event)
{
    if (sfIntRect_contains(&position, event.mouseButton.x, event.mouseButton.y)
        == sfTrue)
        return 1;
    else
        return 0;
}

void detect_nb_life(sfIntRect *rect, game_t *game, sfRenderWindow *window,
sfEvent event)
{
    sfVector2f vector = {0, 0};
    sfVector2f scale = {0.37, 0.37};
    int check = 0;
    sfSprite_setScale(game->sprite_life, scale);
    sfSprite_setPosition(game->sprite_life, vector);
    if (game->life_castle > 39)
        rect->left = 0;
    if (game->life_castle < 40 && game->life_castle > 19)
        rect->left = 550;
    if (game->life_castle < 20 && game->life_castle > -1)
        rect->left = 1100;
    else if (game->life_castle < 0) {
        check = game_over_start(window, event);
        if (check == 84)
            game->end = 84;
        else if (check == 1)
            game->end = 1;
        else
            game->end = 2;
    }
    sfSprite_setTextureRect(game->sprite_life, game->life_rect);
    sfRenderWindow_drawSprite(window, game->sprite_life, NULL);
}

void dispatche(game_t *game, sfRenderWindow *window, sfEvent event, gui_t *gui)
{
    hit_deplacement(gui->turret, game->mob_list, gui, game);
    detect_nb_life(&game->life_rect, game, window, event);
    text_display(game, window);
    check_win(window, event, game);
}
