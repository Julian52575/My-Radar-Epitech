/*
** EPITECH PROJECT, 2022
** my radar
** File description:
** planes goes KABOOOOOOOOOOOOOOOOm
*/
#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include "my_csfml.h"

int help(void);
int generate(int argc, char **argv);

struct aircraft {
    int id;
    sfRectangleShape *rect;
    float x;
    float y;
    float x_arrival;
    float y_arrival;
    sfVector2f vector;
    float speed;
    float delay; // -1 per second until > 0
    int status;
    struct aircraft *next;
    struct aircraft *prev;
};

struct tower {
    sfCircleShape *circ;
    float x;
    float y;
    float radius;
    struct tower *next;
    struct tower *prev;
};

struct point_proches {
    sfVector2f p_p_cerc;
    sfVector2f p_p_rect;
};

struct my_radar {
    sfSprite *background;
    sfText *timer;
    struct aircraft *a;
    sfSprite *a_sprite;
    struct tower *t;
    sfSprite *t_sprite;
    sfSprite *c_point;
    sfSprite *r_point;
    float game_speed;
    float delay_buffer;
    sfText *txt_speed;
    int s_button;
    int l_button;
    int p_button;
    int a_button;
    int m_button;
    int d_button;
    sfSprite *pikachu;
    sfRectangleShape *pika_rect;
    sfSound *pika_hurt;
    float x_pikachu;
    float y_pikachu;
    sfSprite *p_point;
    sfSprite **TableauS;
    sfSound **TableauSound;
    float sound_buffer;
};

int create_my_radar(struct my_radar **mr, struct csfml_tools **ct,
int argc, char **argv);

int get_argv(int argc, char **argv, struct aircraft **a, struct tower **t);
int fill_structures(int fd, struct aircraft **a, struct tower **t, int stop);
int add_new_data(struct aircraft **a, struct tower **t, char **data);
void add_tower(char **data, struct tower **t);
void add_aircraft(char **data, struct aircraft **a);
sfVector2f get_vector(int x, int y, int x_arrival, int y_arrival);
void which_pokemon(struct aircraft *element);

void free_my_radar(struct my_radar *mr);
void free_tower(struct tower *t);
void free_aircraft(struct aircraft *a);

void game_loop(struct csfml_tools *ct, struct my_radar *mr);
void display(struct my_radar *mr, struct csfml_tools *ct);
void display_aircraft(struct my_radar *mr, struct csfml_tools *ct);
void display_tower(struct my_radar *mr, struct csfml_tools *ct);
void display_points_proches(sfVector2f p1, sfVector2f p2,
struct csfml_tools *ct, struct my_radar *mr);
void display_points_proches_p(sfVector2f p1, sfVector2f p2,
struct csfml_tools *ct, struct my_radar *mr);
void display_pikachu(struct my_radar *mr, struct csfml_tools *ct);

void mouvement(struct my_radar *mr, struct csfml_tools *ct);
void remove_airplane(struct my_radar *mr, struct aircraft *a, int id);
void chained_colision(struct my_radar *mr, struct csfml_tools *ct);
int pikachu_colision(struct my_radar *mr, struct csfml_tools *ct);

void rectangle_colision(struct my_radar *mr);
int all_edge_colision(sfRectangleShape *rect1, sfRectangleShape *rect2);

int circle_and_rect_colision(sfRectangleShape *rect, sfCircleShape *circ,
struct csfml_tools *ct, struct my_radar *mr);
int circle_and_rect_colision_p(sfRectangleShape *rect, sfCircleShape *circ,
struct csfml_tools *ct, struct my_radar *mr);
int two_points_colision(sfVector2f pointA, sfVector2f pointB,
float precisionX, float precisionY);

sfVector2f get_nearest_point_rect(sfVector2f perimetre_rect,
sfVector2f pos_rect, sfVector2f centre_cerc);
sfVector2f get_nearest_point_circle(sfVector2f difference,
sfVector2f centre_cer, float radius);

int end_game(struct my_radar *mr);
