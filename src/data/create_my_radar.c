/*
** EPITECH PROJECT, 2022
** main
** File description:
** main for my radar
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

static void create_array(struct my_radar **mr)
{
    (*mr)->TableauS = malloc( sizeof(sfSprite *) * 4);
    (*mr)->TableauS[0] = create_sprite("assets/floravol.png", 1, 1);
    (*mr)->TableauS[1] = create_sprite("assets/magneti.png", 1, 1);
    (*mr)->TableauS[2] = create_sprite("assets/ho-oh.png", 1, 1);
    (*mr)->TableauS[3] = create_sprite("assets/togetic.png", 1, 1);

    (*mr)->TableauSound = malloc( sizeof(sfSprite *) * 4);
    (*mr)->TableauSound[0] = create_sound("assets/skiploom.ogg");
    (*mr)->TableauSound[1] = create_sound("assets/magnemite.ogg");
    (*mr)->TableauSound[2] = create_sound("assets/hooh.ogg");
    (*mr)->TableauSound[3] = create_sound("assets/togetic.ogg");
}

static void create_sprites(struct my_radar **mr)
{
    (*mr)->background = create_sprite("assets/johto.png", 2, 2);
    sfVector2f bpos = {-100, -100};
    sfSprite_setPosition((*mr)->background, bpos);
    (*mr)->a_sprite = create_sprite("assets/floravol.png", 1, 1);
    (*mr)->t_sprite = create_sprite("assets/tower.png", 1, 1);
    (*mr)->r_point = create_sprite("assets/exclamationB.png", 1, 1);
    (*mr)->c_point = create_sprite("assets/exclamationG.png", 1, 1);
    (*mr)->p_point = create_sprite("assets/exclamationP.png", 1, 1);
    (*mr)->pikachu = create_sprite("assets/pikachu.png", 1, 1);
    sfSprite_setTextureRect((*mr)->pikachu, create_texture_rect(35, 36, 0, 0));
    (*mr)->pika_rect = create_rectangle(35, 36, 0, 0);
    sfRectangleShape_setOutlineColor((*mr)->pika_rect, sfYellow);
    sfRectangleShape_setOutlineThickness((*mr)->pika_rect, 3.00);
    (*mr)->pika_hurt = create_sound("assets/pika_hurt.ogg");
    (*mr)->timer = create_text("Lol", "assets/pkmndp.ttf", 48);
    (*mr)->txt_speed = create_text("Lol", "assets/pkmndp.ttf", 30);
    sfVector2f tpos = {1720, 70};
    sfText_setPosition((*mr)->txt_speed, tpos);
    sfText_setColor((*mr)->txt_speed, sfRed);
}

static void create_int(struct my_radar **mr)
{
    (*mr)->game_speed = 1.00;
    (*mr)->delay_buffer = 0.00;
    (*mr)->s_button = 0;
    (*mr)->l_button = 0;
    (*mr)->p_button = 0;
    (*mr)->a_button = 0;
    (*mr)->x_pikachu = 1000;
    (*mr)->y_pikachu = 500;
    if ( (*mr)->t) {
        (*mr)->x_pikachu = (*mr)->t->x;
        (*mr)->y_pikachu = (*mr)->t->y;
    }
    (*mr)->sound_buffer = 5.42;
    (*mr)->m_button = 0;
    (*mr)->d_button = 0;
}

int create_my_radar(struct my_radar **mr, struct csfml_tools **ct,
int argc, char **argv)
{
    create_ct(ct, "My radar");
    struct aircraft *a = NULL;
    struct tower *t = NULL;
    if (get_argv(argc, argv, &a, &t) == 84) return 84;
    (*mr)->a = a;
    (*mr)->t = t;
    create_sprites(mr);
    create_int(mr);
    create_array(mr);
    return 0;
}
