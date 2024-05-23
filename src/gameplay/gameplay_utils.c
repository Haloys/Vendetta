/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process gameplay loop
*/

#include <stdio.h>

#include "my_game.h"
#include "map.h"
#include "enemies.h"
#include "player.h"
#include "gameplay.h"
#include "game_npc.h"
#include "utils.h"

static void draw_overlay(game_data_t *game, sfVector2f relativepos)
{
    sfSprite *sp_health = get_sprite(game, SP_HEALTH2);
    sfText *health;
    char buffer[10];

    sprintf(buffer, "%d", game->player->health);
    relativepos.y += 40;
    relativepos.x += 120;
    sfSprite_setPosition(sp_health, relativepos);
    relativepos.x += 50;
    relativepos.y -= 5;
    health = set_text(game, buffer, 30, relativepos);
    sfText_setStyle(health, sfTextBold);
    sfRenderWindow_drawText(game->window, health, NULL);
    sfRenderWindow_drawSprite(game->window, sp_health, NULL);
    sfText_destroy(health);
}

void display_overlay(game_data_t *game)
{
    sfVector2f view_size = sfView_getSize(game->game_view);
    sfVector2f relativepos = {game->view_pos.x + view_size.x / 2,
        game->view_pos.y - view_size.y / 2};
    sfText *passiv;
    char buffer[30];

    relativepos.y += 30;
    if (game->is_passive) {
        relativepos.x -= 240;
        sprintf(buffer, "PASSIVE MODE [%s]",
            key_to_string(game->keybinds[Hostile].code));
        passiv = set_text(game, buffer, 22, relativepos);
    } else {
        relativepos.x -= 240;
        sprintf(buffer, "HOSTILE MODE [%s]",
            key_to_string(game->keybinds[Hostile].code));
        passiv = set_text(game, buffer, 22, relativepos);
    }
    sfRenderWindow_drawText(game->window, passiv, NULL);
    sfText_destroy(passiv);
    draw_overlay(game, relativepos);
}
