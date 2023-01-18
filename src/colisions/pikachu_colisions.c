/*
** EPITECH PROJECT, 2022
** chained colision
** File description:
** check the colisions and do stuff
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

static int pikachu_colision2(struct my_radar *mr, struct csfml_tools *ct)
{
    struct aircraft *tmp_a = mr->a;
    while (mr->a) {
        if (mr->a->status != 0 || mr->a->delay > ct->time_buffer) {
            mr->a = mr->a->next;
            continue;
        }
        if (all_edge_colision(mr->pika_rect, mr->a->rect) == 1) {
            sfSound_play(mr->pika_hurt);
            remove_airplane(mr, mr->a, -1);
            mr->a = tmp_a;
            return 1;
        }
        mr->a = mr->a->next;
    }
    mr->a = tmp_a;
    return 0;
}

int pikachu_colision(struct my_radar *mr, struct csfml_tools *ct)
{
    struct aircraft *tmp_a = mr->a;
    struct tower *tmp_t = mr->t;
    while (mr->t && (mr->m_button % 2 == 0) ) {
        if (circle_and_rect_colision_p(mr->pika_rect, mr->t->circ, ct, mr)
        == 1) {
            mr->t = tmp_t;
            return 0;
        }
        mr->t = mr->t->next;
    } mr->t = tmp_t;
    mr->a = tmp_a;
    return pikachu_colision2(mr, ct);
}
