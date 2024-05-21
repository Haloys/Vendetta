/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process gameplay loop
*/

#include "my_game.h"

static void set_shader_elements(game_data_t *game, sfVector2u resolution,
    sfTexture *texture, sfSprite *sprite)
{
    sfShader *shader = game->assets.shaders[SH_MAIN_DARKNESS];
    sfRenderStates states = { .blendMode = sfBlendAlpha, .shader = shader,
        .texture = texture, .transform = sfTransform_Identity };

    if (shader == NULL)
        return;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, game->view_pos);
    sfSprite_setOrigin(sprite, (sfVector2f){WINDOW_WIDTH / 2,
        WINDOW_HEIGHT / 2});
    sfSprite_setScale(sprite,
        (sfVector2f){game->view_zoom + 0.03f, game->view_zoom + 0.03f});
    sfShader_setVec2Uniform(shader, "resolution",
        (sfVector2f){resolution.x, resolution.y});
    sfShader_setFloatUniform(shader, "time",
        sfTime_asSeconds(sfClock_getElapsedTime(game->clock)));
    sfRenderWindow_drawSprite(game->window, sprite, &states);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void apply_shader(game_data_t *game)
{
    sfVector2u resolution = sfRenderWindow_getSize(game->window);
    sfTexture *texture = sfTexture_create(WINDOW_WIDTH, WINDOW_HEIGHT);
    sfSprite *sprite = sfSprite_create();

    if (texture == NULL || sprite == NULL)
        return;
    set_shader_elements(game, resolution, texture, sprite);
}
