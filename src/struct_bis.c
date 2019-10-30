/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** turret_function
*/

#include "game.h"

hit_t *new_hit(char *name, sfIntRect rect, int nb)
{
    hit_t *new = malloc(sizeof(hit_t));

    new->key = nb;
    new->pos = 0;
    new->rect = rect;
    new->hit = init_sprite(name, rect);
    return new;
}

gui_button_t *new_gui_button(char *name, sfIntRect rect, sfVector2f vector,
        sfIntRect click)
{
    gui_button_t *new = malloc(sizeof(gui_button_t));

    new->clickable = click;
    new->key = gui_flag_finder(0);
    new->pos = 0;
    new->rect = rect;
    new->position = vector;
    new->sprite = init_sprite(name, rect);
    new->next = NULL;
    sfSprite_setPosition(new->sprite, new->position);
    return new;
}

sfText *text_create(game_t *game)
{
    sfFont *font = sfFont_createFromFile("png/button/BebasNeue.otf");
    sfText *text = sfText_create();
    sfVector2f vector = {900, 20};

    sfText_setPosition(text, vector);
    sfText_setString(text, int_to_string(game->gold));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    return text;
}

void text_display(game_t *game, sfRenderWindow *window)
{
    sfText_setString(game->text, int_to_string(game->gold));
    sfRenderWindow_drawText(window, game->text, NULL);
}

void gold_define(gui_button_t *turret)
{
    gui_button_t *begin = turret;
    turret->cost = 75;
    turret = turret->next;
    turret->cost = 100;
    turret = turret->next;
    turret->cost = 125;
    turret = turret->next;
    turret->cost = 150;
    turret = begin;
}