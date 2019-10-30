/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** main function
*/

#ifndef GAME_H
#define GAME_H

#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/Audio/Music.h>
#include <stddef.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "gui.h"
#include "linked_list.h"
#include "placer_turret.h"

typedef struct aim {
    sfVector2i mouse;
    sfVector2f coord;
    sfSprite *aim;
}aim_t;

typedef struct my_game{
    sfIntRect rect;
    sfIntRect rect_castle;
    sfIntRect life_rect;
    sfSprite *sprite;
    sfSprite *sprite_castle;
    sfSprite *sprite_life;
    sfMusic *hit;
    sfMusic *die;
    int life_castle;
    int taille_sprite;
    int fin_sprite;
    int hauteur_sprite;
    int end;
    int gold;
    int cost;
    sfClock *clock;
    sfText *text;
    sfVector2f position;
    sfTime time;
    float second;
    mob_t *mob_list;
    aim_t *aim;
    char *player_name;
}game_t;

aim_t *init_aim(void);
void aim(aim_t *aim, sfRenderWindow *window);
void button_reset(gui_t *gui);
int first_button_pos(sfEvent event, gui_t *gui);
int second_button_pos(sfEvent event, gui_t *gui);
int third_button_pos(sfEvent event, gui_t *gui);
int fourth_button_pos(sfEvent event, gui_t *gui);
void button_check(sfEvent event, gui_t *gui, game_t *game);
int event_check(sfRenderWindow *window, sfEvent event, gui_t *gui, game_t *g);
sfVector2f init_vector(int x, int y);
void pos_create(gui_t *gui);
gui_t *init_gui(void);
int gui_display(sfRenderWindow *window, gui_t *gui);
void block_button(int key, gui_t *gui);
void declick_button(int key, gui_t *gui);
int button_choose(int first, int second, int third, int fourth);
int gui_event(sfEvent event, gui_t *gui, int wait_event);
void set_turret_pos(int nb, gui_t *gui);
int gui_check(sfEvent event, gui_t *gui, game_t *game);
sfIntRect button_change(sfIntRect rect, sfSprite *tower, int key);
void init_scale(game_t *game);
sfSprite *init_sprite(char *str, sfIntRect rect);
game_t *init_game(void);
void set_all_position(game_t *game);
int game_start(sfRenderWindow *window, sfEvent event, char *name);
gui_button_t *gui_button_initialiser(void);
turret_t *new_turret(char *name, sfIntRect rect, int key, hit_t *hit);
button_t *new_button(char *name, sfIntRect rect, sfVector2f pos,
        sfVector2f turret_pos);
turret_t *turret_initialiser(void);
button_t *button_initialiser(void);
name_t *init_name(char *name_1, char *name_2, char *name_3);
mob_name_t *init_mob_name(void);
mob_t *init_mob(int width, int height, name_t *mob_name, int nb);
def_sprite_t *init_def_sprite(int taille, int fin, int hauteur);
mob_t *list_create(void);
int main(int argc, char **argv);
sfIntRect intrect_create(int top, int left, int width, int height);
int menu_mouse_click(sfEvent event, sfRenderWindow *window);
int menu_loop(sfRenderWindow *window, sfEvent event, sfSprite *sprite,
        aim_t *my_aim);
int menu_start(sfRenderWindow *window, sfEvent event);
void set_and_move(game_t *game, sfRenderWindow *window);
void check_position(game_t *game, int i, sfRenderWindow *window);
void second_loop(game_t *game, sfRenderWindow *window, int i);
int game_loop(sfRenderWindow *window, sfEvent event, game_t *game, gui_t *gui);
void give_and_set(turret_t *turret, button_t *button);
void finder(int key, gui_t *gui, button_t *button);
void turret_finder(gui_t *gui, sfEvent event, int key, game_t *game);
void rec_mouvement_run(sfIntRect *rec, game_t *game);
int check_click(sfIntRect position, sfEvent event);
void turret_check(sfEvent event, gui_t *gui);
void init_scale_turret(gui_t *gui);
void reset_drawing(gui_t *gui);
button_t *button_initialiser(void);
turret_t *turret_initialiser(void);
sfVector2f init_vector(int x, int y);
aim_t *init_aim(void);
void aim(aim_t *aim, sfRenderWindow *window);
gui_button_t *gui_button_initialiser(void);
void set_button_pos(gui_t *gui);
void turret_drawing(gui_t *gui, sfRenderWindow *window, int i);
void plus_drawing(gui_t *gui, sfRenderWindow *window, int i);
gui_button_t *new_gui_button(char *name, sfIntRect rect, sfVector2f vector,
        sfIntRect click);
void block_and_reset(gui_t *gui);
void check_turret_placed(gui_t *gui, int i);
void rec_mouvement_turret(sfIntRect *rec, gui_t *gui);
hit_t *hit_initialiser(void);
hit_t *new_hit(char *name, sfIntRect rect, int nb);
void rect_moover(int left, sfIntRect *rect);
void bullet_display(gui_t *gui, sfRenderWindow *window);
void bullet_placer(gui_t *gui);
void bullet_scale(turret_t *turret);
void hit_rect(turret_t *turret, gui_t *gui, game_t *game);
void hit_deplacement(turret_t *turret, mob_t *mob, gui_t *gui, game_t *game);
sfVector2f check_mob_position(mob_t *mob);
void rec_mouvement_hit(sfIntRect *rec, gui_t *gui);
void hit_touch(gui_t *gui, game_t *game);
void hit_data(gui_t *gui);
void neg_life(game_t *game, gui_t *gui);
void detect_nb_life(sfIntRect *rect, game_t *game, sfRenderWindow *window,
        sfEvent event);
int die_mob_check(mob_t *mob_list, int i, sfRenderWindow *window, game_t *game);
int game_over_start(sfRenderWindow *window, sfEvent event);
int game_over_menu(sfRenderWindow *window, sfEvent event, sfSprite *sprite,
        aim_t *my_aim);
int game_over_mouse_clic(sfEvent event);
char *int_to_string(int score);
sfText *text_create(game_t *game);
void text_display(game_t *game, sfRenderWindow *window);
void gold_define(gui_button_t *turret);
void check_win(sfRenderWindow *window, sfEvent event, game_t *game);
void sub_function(game_t *game);
void free_all(game_t *game, gui_t *gui);
void free_game(game_t *game);
void free_mob(mob_t *mob);
void free_mob_name(mob_name_t *mob_name);
void free_my_name(name_t *name);
void free_aim(aim_t *aim);
void free_gui(gui_t *gui);
void free_button(button_t *button);
void free_turret(turret_t *turret);
void free_hit(hit_t *hit);
void free_gui_button(gui_button_t *gui_button);
void dispatche(game_t *game, sfRenderWindow *window, sfEvent event, gui_t *gui);
void change_life(game_t *game);
int how_to_play(sfRenderWindow *window);
void check_mouse(gui_t *gui, aim_t *aim);
void chang_color(sfSprite *sprite, sfColor color);
void loop_manager(sfRenderWindow *window, sfEvent event, game_t *game,
        gui_t *gui);
int gui_flag_finder(int flag);
char *my_str_c_dup(char *src, char *second_src);
int my_strlen(char *str);
char *my_str_c_dup(char *src, char *second_src);
int score_manager(sfRenderWindow *window);

#endif //GAME_H