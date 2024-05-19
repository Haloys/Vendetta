/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Utils
*/

#include "my_game.h"

inline int play_sound(game_data_t *game, sound_id_t id)
{
    sfSound_play(game->assets.sound[id]);
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

sfText *set_text(game_data_t *game, char *txt, int size, sfVector2f pos)
{
    sfText *text = sfText_create();

    if (text == NULL)
        return NULL;
    sfText_setString(text, txt);
    sfText_setFont(text, game->font);
    sfText_setCharacterSize(text, size);
    sfText_setFillColor(text, sfColor_fromRGB(250, 250, 250));
    sfText_setPosition(text, pos);
    return text;
}

sfText *set_text_const(game_data_t *game, const char *txt,
    int size, sfVector2f pos)
{
    return set_text(game, (char *)txt, size, pos);
}
