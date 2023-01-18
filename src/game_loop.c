/*
** EPITECH PROJECT, 2022
** game loop
** File description:
** ~ ~
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <stdio.h>
#include "my_csfml.h"
#include "my_radar.h"
#include "my.h"

static int do_sfevent_stuff(struct csfml_tools *ct)
{
    while (sfRenderWindow_pollEvent(ct->window, &ct->event) == sfTrue) {
        if (ct->event.type == sfEvtClosed) {
            sfRenderWindow_close(ct->window);
            return -1;
        }
    }
    return 1;
}

static int do_event_stuff(struct csfml_tools *ct, struct my_radar *mr)
{
    int a = 1;
    a = do_sfevent_stuff(ct);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        sfRenderWindow_clear(ct->window, sfBlue);
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue) mr->s_button += 1;
    if (sfKeyboard_isKeyPressed(sfKeyL) == sfTrue) mr->l_button += 1;
    if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue) mr->p_button += 1;
    if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue) mr->a_button += 1;
    if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue) mr->d_button += 1;
    if (sfKeyboard_isKeyPressed(sfKeyM) == sfTrue) mr->m_button += 1;
    if (sfKeyboard_isKeyPressed(sfKeyAdd) == sfTrue)
        mr->game_speed += 1.0;
    if (sfKeyboard_isKeyPressed(sfKeySubtract) == sfTrue
    && mr->game_speed) mr->game_speed -= 1.0;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad0) == sfTrue) mr->game_speed = 0.0;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad9) == sfTrue) mr->game_speed = 9.0;
    if (mr->game_speed <= 0) mr->game_speed = 0.1;
    return a;
}

static void move_pikachu(struct my_radar *mr)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
        mr->y_pikachu -= 1.5 * mr->game_speed;
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
        mr->y_pikachu += 1.5 * mr->game_speed;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        sfSprite_setTextureRect(mr->pikachu,
        update_texture_rect(mr->pikachu, 0, 0));
        mr->x_pikachu -= 2.5 * mr->game_speed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        sfSprite_setTextureRect(mr->pikachu,
        update_texture_rect(mr->pikachu, 0, 38));
        mr->x_pikachu += 2.5 * mr->game_speed;
    }
    if (mr->x_pikachu < -40.0) mr->x_pikachu = 1940;
    if (mr->x_pikachu > 1940.0) mr->x_pikachu = -30;
    if (mr->y_pikachu < -40.0) mr->y_pikachu += 1040.0;
    if (mr->y_pikachu > 1020.0) mr->y_pikachu -= 1040.0;
}

static int game_loop2(struct csfml_tools *ct, struct my_radar *mr)
{
    sfRenderWindow_display(ct->window);
    sfRenderWindow_drawSprite(ct->window, mr->background, NULL);
    display(mr, ct);
    if (ct->mouvement_buffer > 0.02) {
        ct->time_buffer += 0.02 * mr->game_speed;
        mouvement(mr, ct);
        chained_colision(mr, ct);
        move_pikachu(mr);
        if (pikachu_colision(mr, ct) == 1)
        ct->mouvement_buffer = 0;
    }
    if (ct->event_buffer > 0.2) {
        ct->event_buffer = 0;
        return do_event_stuff(ct, mr);
    }
    return end_game(mr);
}

void game_loop(struct csfml_tools *ct, struct my_radar *mr)
{
    int a = 1;
    while (a > 0) {
        ct->time = sfClock_getElapsedTime(ct->clock);
        ct->time_buffer += ct->time.microseconds / 1000000.0;
        ct->event_buffer += ct->time.microseconds / 1000000.0;
        ct->mouvement_buffer += ct->time.microseconds / 1000000.0;
        mr->sound_buffer += ct->time.microseconds / 1000000.0;
        mr->delay_buffer += ct->time.microseconds / 1000000.0;
        sfClock_restart(ct->clock);
        a = game_loop2(ct, mr);
    }
}

        // if (circle_and_rect_colision(sfRectangleShape_getSize(rect),
        // sfRectangleShape_getPosition(rect),
        // sfCircleShape_getRadius(circle),
        // sfCircleShape_getPosition(circle)) == 1)
