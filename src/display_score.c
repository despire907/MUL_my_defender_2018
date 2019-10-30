/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "scorboard.h"
#include "game.h"

void display_score_manager(sfText *text, sfFont *font, sfVector2f coord,
char *str)
{
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, coord);
}

void display_score(sfRenderWindow *window, char **score)
{
    int count = 0;
    int x = 270;
    int y = 200;
    sfVector2f coord;
    sfFont *font = sfFont_createFromFile("png/button/BebasNeue.otf");
    sfText *text = sfText_create();
    if (score == NULL)
        return;
    while (score[count] != NULL) {
        coord.x = x;
        coord.y = y;
        display_score_manager(text, font, coord, score[count]);
        sfRenderWindow_drawText(window, text, NULL);
        y = y + 75;
        if (count == 5) {
            x = x + 300;
            y = 200;
        }
        count++;
    }
    sfText_destroy(text);
}

int score_manager(sfRenderWindow *window)
{
    sfEvent event;
    sfTexture *texture = sfTexture_createFromFile("png/high_score.png", NULL);
    sfSprite *sprite = sfSprite_create();
    char **score = scorboard_obtain();
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (1) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
                return (2);
            }
            if (event.type == sfEvtKeyPressed &&
            event.key.code == sfKeyEscape)
                return (0);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        display_score(window, score);
        sfRenderWindow_display(window);
    }
    return (0);
}