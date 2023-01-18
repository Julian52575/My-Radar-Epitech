/*
** EPITECH PROJECT, 2022
** create text
** File description:
** returns a sf text
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

sfText *create_text(char *str, char *font_file, unsigned int size)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile(font_file);
    sfText_setFont(txt, font);

    sfText_setString(txt, str);
    sfText_setCharacterSize(txt, size);
    sfVector2f pos = {1700, 100};
    sfText_setPosition(txt, pos);
    return txt;
}
