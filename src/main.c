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

void free_aircraft(struct aircraft *a)
{
    if (a) {
        if (a->next) {
            free_aircraft(a->next);
        }
        sfRectangleShape_destroy(a->rect);
        free(a);
    }
}

void free_tower(struct tower *t)
{
    if (t) {
        if (t->next) {
            free_tower(t->next);
        }
        sfCircleShape_destroy(t->circ);
        free(t);
    }
}

void free_my_radar(struct my_radar *mr)
{
    free_aircraft(mr->a);
    free_tower(mr->t);
    sfSprite_destroy(mr->background);
    sfText_destroy(mr->timer);
    sfSprite_destroy(mr->a_sprite);
    sfSprite_destroy(mr->t_sprite);
    sfSprite_destroy(mr->c_point);
    sfSprite_destroy(mr->r_point);
    sfText_destroy(mr->txt_speed);
    sfSprite_destroy(mr->pikachu);
    sfRectangleShape_destroy(mr->pika_rect);
    sfSound_destroy(mr->pika_hurt);
    sfSprite_destroy(mr->p_point);
    free(mr);
}

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 5) return 84;
    if (my_str_compare(argv[1], "-g") == 1) return generate(argc, argv);
    if (my_str_compare(argv[1], "-h") == 1 ) return help();
    struct csfml_tools *ct = malloc(sizeof(struct csfml_tools) );
    struct my_radar *mr = malloc(sizeof(struct my_radar));
    if (create_my_radar(&mr, &ct, argc, argv) == 84) {
        free_my_radar(mr);
        my_putstr("Mauvais script :(\n");
        return 84;
    }
    game_loop(ct, mr);
    free_my_radar(mr);
    return 0;
}
