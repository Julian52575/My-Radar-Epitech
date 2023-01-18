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

static int chained_colision_for_tower(struct my_radar *mr,
struct csfml_tools *ct)
{
    if (mr->m_button % 2 == 1) return 0;
    struct tower *tmp_t = mr->t;
    while (mr->t) {
        if (circle_and_rect_colision(mr->a->rect, mr->t->circ, ct, mr) == 1) {
                mr->t = tmp_t;
                return 1;
        }
        mr->t = mr->t->next;
    }
    mr->t = tmp_t;
    return 0;
}

static int chained_colision_for_craft2(struct my_radar *mr,
struct csfml_tools *ct)
{
    struct aircraft *tmp2 = mr->a;
    tmp2 = tmp2->next;
    while (tmp2) {
        if (tmp2->status != 0 || tmp2->delay > ct->time_buffer) {
            tmp2 = tmp2->next;
            continue;
        }
        if (all_edge_colision(mr->a->rect, tmp2->rect) == 1) {
            remove_airplane(mr, tmp2, -1);
            return 1;
        }
        tmp2 = tmp2->next;
    }
    return 0;
}

//If colision, returns 1 and remove the aircraft that colided with mr->a
static int chained_colision_for_craft(struct my_radar *mr,
struct csfml_tools *ct)
{
    struct aircraft *tmp = mr->a;
    tmp = tmp->prev;
    while (tmp) {
        if (tmp->status != 0 || tmp->delay > ct->time_buffer) {
            tmp = tmp->prev;
            continue;
        }
        if (all_edge_colision(mr->a->rect, tmp->rect) == 1) {
            remove_airplane(mr, tmp, -1);
            return 1;
        }
        tmp = tmp->prev;
    }
    return chained_colision_for_craft2(mr, ct);
}

void chained_colision(struct my_radar *mr, struct csfml_tools *ct)
{
    if (mr->l_button % 2 == 1) return;
    struct aircraft *tmp_a = mr->a;
    while (mr->a) {
        if (mr->a->status != 0 || mr->a->delay > ct->time_buffer) {
            mr->a = mr->a->next;
            continue;
        }
        if (chained_colision_for_tower(mr, ct) == 1) {
            mr->a = mr->a->next;
            continue;
        }
        if (chained_colision_for_craft(mr, ct) == 1) {
            remove_airplane(mr, mr->a, -1);
        }
        mr->a = mr->a->next;
    }
    mr->a = tmp_a;
}
