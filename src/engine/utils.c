/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include <stdlib.h>
#include "my_game.h"
#include "entity.h"

inline int play_sound(game_data_t *game, sound_id_t id)
{
    sfSound *sound = sfSound_create();

    if (sound == NULL)
        return RET_FAIL;
    sfSound_setBuffer(sound, game->assets.sound[id]);
    sfSound_play(sound);
    return RET_NONE;
}

inline sfSprite *get_sprite(game_data_t *game, sprite_id_t id)
{
    return game->assets.sprite[id];
}

inline int is_rect_click(sfFloatRect const *rect, sfVector2f mouse)
{
    return mouse.x >= rect->left && mouse.x <= rect->left + rect->width
        && mouse.y >= rect->top && mouse.y <= rect->top + rect->height;
}

void new_set_text(game_data_t *game, char *txt, int size, sfVector2f pos)
{
    sfText_setString(game->help_text, txt);
    sfText_setFont(game->help_text, game->font);
    sfText_setCharacterSize(game->help_text, size);
    sfText_setFillColor(game->help_text, sfColor_fromRGB(250, 250, 250));
    sfText_setPosition(game->help_text, pos);
    sfRenderWindow_drawText(game->window, game->help_text, NULL);
}

sfText *set_text(game_data_t *game, char *txt, int size, sfVector2f pos)
{
    sfText *text = sfText_create();

    if (text == NULL)
        return;
    sfText_setString(text, txt);
    sfText_setFont(text, game->font);
    sfText_setCharacterSize(text, size);
    sfText_setFillColor(text, sfColor_fromRGB(250, 250, 250));
    sfText_setPosition(text, pos);
    return text;
}
