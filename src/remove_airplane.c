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
#include "my.h"

void remove_airplane(struct my_radar *mr, struct aircraft *a, int id)
{
    if (mr->sound_buffer > 5.0) {
        sfSound_play(mr->TableauSound[a->id]);
        mr->sound_buffer = 0.0;
    }
    if (a->prev) a->prev->next = a->next;
    if (a->next) a->next->prev = a->prev;
    a->status = id;
    return;
}
