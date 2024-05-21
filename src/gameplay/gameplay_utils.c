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
    sfVector2f relativepos = {game->view_pos.x + WINDOW_WIDTH / 2,
        game->view_pos.y - WINDOW_HEIGHT / 2};
    sfText *passiv;

    relativepos.y += 30;
    if (game->is_passive) {
        relativepos.x -= 240;
        passiv = set_text(game, "PASSIVE MODE [W]", 22, relativepos);
    } else {
        relativepos.x -= 240;
        passiv = set_text(game, "HOSTILE MODE [W]", 22, relativepos);
    }
    sfRenderWindow_drawText(game->window, passiv, NULL);
    sfText_destroy(passiv);
    draw_overlay(game, relativepos);
    display_notifications(game, &game->notifications);
    update_notifications(&game->notifications);
}
