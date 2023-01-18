/*
** EPITECH PROJECT, 2022
** produit scalaire
** File description:
** produit scalaire
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
#include <math.h>
#include "my_csfml.h"
#include "my.h"

float produit_scalaire(sfVector2f U, sfVector2f V, int norme)
{
    float ps = (U.x * V.x) +
    (U.y * V.y);
    if (norme > 0) {
        float total_x = pow(U.x, 2) + pow(U.y, 2);
        total_x = sqrtf(total_x);
        float total_y = pow(V.x, 2) + pow(V.y, 2);
        total_y = sqrtf(total_y);
        ps = total_x * total_y;
    }
    return ps;
}
