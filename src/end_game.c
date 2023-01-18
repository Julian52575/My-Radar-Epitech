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

int end_game(struct my_radar *mr)
{
    struct aircraft *tmp = mr->a;
    while (mr->a) {
        if (mr->a->status == 0) {
            mr->a = tmp;
            return 1;
        }
        mr->a = mr->a->next;
    }
    mr->a = tmp;
    return 0;
}
