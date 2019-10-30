/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** linked list function
*/

#include "game.h"

name_t *init_name(char *name_1, char *name_2, char *name_3)
{
    name_t *new = malloc(sizeof(name_t));

    new->name_1 = name_1;
    new->name_2 = name_2;
    new->name_3 = name_3;

    return (new);
}

mob_name_t *init_mob_name(void)
{
    mob_name_t *new = malloc(sizeof(mob_name_t));

    new->name_mob_1 = init_name("png/mob_one/attack.png", "png/mob_one/die.png",
            "png/mob_one/walk.png");
    new->name_mob_2 = init_name("png/mob_two/attack.png", "png/mob_two/die.png",
            "png/mob_two/walk.png");
    new->name_mob_3 = init_name("png/mob_three/attack.png",
            "png/mob_three/die.png", "png/mob_three/walk.png");

    return (new);
}

mob_t *init_mob(int width, int height, name_t *mob_name, int nb)
{
    mob_t *new = malloc(sizeof(mob_t));

    srand(nb);
    new->top = 0;
    new->left = 0;
    new->width = width;
    new->height = height;
    new->life = 3;
    new->dep.x = 5;
    new->dep.y = 0;
    new->position.x = nb;
    new->position.y = rand() % (500);
    new-> rect = intrect_create(0, 0, width, height);
    new->attack_sprite = init_sprite(mob_name->name_1, new->rect);
    new->die_sprite = init_sprite(mob_name->name_2, new->rect);
    new->walk_sprite = init_sprite(mob_name->name_3, new->rect);
    new->next = NULL;

    return (new);
}

def_sprite_t *init_def_sprite(int taille, int fin, int hauteur)
{
    def_sprite_t *new = malloc(sizeof(def_sprite_t));

    new->taille_sprite = taille;
    new->fin_sprite = fin;
    new->hauteur_sprite = hauteur;

    return (new);
}

mob_t *list_create(void)
{
    mob_name_t *mob_name = init_mob_name();
    mob_t *mob_list = init_mob((1176 / 4), (1375 / 5), mob_name->name_mob_1,
            -110);
    mob_list->def_sprite = init_def_sprite(294, 1176, 275);
    mob_t *begin = mob_list;
    mob_list->next = init_mob((1016 / 4), (1025 / 5), mob_name->name_mob_2,
            -200);
    mob_list = mob_list->next;
    mob_list->def_sprite = init_def_sprite(254, 1016, 205);
    mob_list->next = init_mob((1168 / 4), (1240 / 5), mob_name->name_mob_3,
            -250);
    mob_list = mob_list->next;
    mob_list->def_sprite = init_def_sprite(292, 1168, 248);
    mob_list = begin;

    return (mob_list);
}