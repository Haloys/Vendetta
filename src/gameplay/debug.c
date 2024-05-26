/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process gameplay loop
*/

#include "my_game.h"

void display_debug(game_data_t *game)
{
    sfRenderTexture *debug_overlay = game->debug_overlay;
    sfSprite *sp_debug_overlay = sfSprite_create();
    sfVector2u size = sfRenderTexture_getSize(game->debug_overlay);
    sfView *backup = sfView_copy(sfRenderWindow_getView(game->window));
    sfView *view = sfView_createFromRect((sfFloatRect){0, 0, size.x, size.y});

    if (debug_overlay == NULL || backup == NULL || view == NULL)
        return;
    sfRenderTexture_display(debug_overlay);
    sfSprite_setTexture(sp_debug_overlay,
        sfRenderTexture_getTexture(debug_overlay), sfTrue);
    sfRenderWindow_setView(game->window, view);
    sfRenderWindow_drawSprite(game->window, sp_debug_overlay, NULL);
    sfRenderWindow_setView(game->window, backup);
    sfView_destroy(view);
    sfView_destroy(backup);
    sfSprite_destroy(sp_debug_overlay);
}
