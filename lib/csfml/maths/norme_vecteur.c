/*
** EPITECH PROJECT, 2022
** norme
** File description:
** d'un vecteur
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

float get_norme(sfVector2f vecteur)
{
    float total = 0.0;
    total += pow(vecteur.x, 2);
    total += pow(vecteur.y, 2);
    return sqrtf(total);
}
