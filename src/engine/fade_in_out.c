/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** loading
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "my_game.h"
#include "my.h"
#include "score.h"
#include "fade_in_out.h"

static int calculate_fade_in_alpha(fade_in_params_t *params)
{
    sfTime time = sfClock_getElapsedTime(params->clock);
    int elapsed_ms = sfTime_asMilliseconds(time);
    int full_opacity = 255;
    int alpha = (int)((double)elapsed_ms
        / params->fade_duration_ms * full_opacity);

    return alpha > full_opacity ? full_opacity : alpha;
}

void fade_in_all(fade_in_params_t *params)
{
    int alpha;
    sfColor color;

    while (sfTime_asMilliseconds(sfClock_getElapsedTime(params->clock))
        < params->fade_duration_ms) {
        alpha = calculate_fade_in_alpha(params);
        color = sfColor_fromRGBA(255, 255, 255, alpha);
        sfRenderWindow_clear(params->window, sfBlack);
        for (int i = 0; i < params->sprite_count; i++) {
            sfSprite_setColor(params->sprites[i], color);
            sfRenderWindow_drawSprite(params->window,
            params->sprites[i], NULL);
        }
        sfText_setFillColor(params->text, color);
        sfRenderWindow_drawText(params->window, params->text, NULL);
        sfRenderWindow_display(params->window);
    }
}

static int calculate_alpha(fade_in_out_params_t *params)
{
    sfTime time = sfClock_getElapsedTime(params->clock);
    int elapsed_ms = sfTime_asMilliseconds(time);
    int alpha = 255;

    if (elapsed_ms < params->fade_duration_ms) {
        alpha = (int)((double)elapsed_ms / params->fade_duration_ms * 255);
    } else if (elapsed_ms >= params->fade_out_start_ms) {
        alpha = 255 - (int)(((double)(elapsed_ms - params->fade_out_start_ms)
        / (params->total_duration_ms - params->fade_out_start_ms)) * 255);
        alpha = fmax(alpha, 0);
    }
    return alpha;
}

void fade_in_out_all(fade_in_out_params_t *params)
{
    int alpha;
    sfColor color;

    while (sfTime_asMilliseconds(sfClock_getElapsedTime(params->clock))
        < params->total_duration_ms) {
        alpha = calculate_alpha(params);
        color = sfColor_fromRGBA(255, 255, 255, alpha);
        sfRenderWindow_clear(params->window, sfBlack);
        for (int i = 0; i < params->sprite_count; i++) {
            sfSprite_setColor(params->sprites[i], color);
            sfRenderWindow_drawSprite(params->window,
            params->sprites[i], NULL);
        }
        sfText_setFillColor(params->text, color);
        sfRenderWindow_drawText(params->window, params->text, NULL);
        sfRenderWindow_display(params->window);
    }
}
