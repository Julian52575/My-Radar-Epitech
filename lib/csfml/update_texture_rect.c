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

sfIntRect update_texture_rect(sfSprite *sp, int x, int y)
{
    sfIntRect r = sfSprite_getTextureRect(sp);
    r.left = x;
    r.top = y;
    return r;
}
