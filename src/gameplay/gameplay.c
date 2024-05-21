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

static void display_enemies(game_data_t *game)
{
    element_t *tmp = game->enemies.start.next;

    for (int i = 0; i < game->enemies.length; ++i) {
        if (game->map.id == ((enemy_t *)tmp->data)->map_id) {
            update_enemy(game, (enemy_t *)tmp->data);
            draw_enemy(game, (enemy_t *)tmp->data);
        }
        tmp = tmp->next;
    }
}

static void display_npcs(game_data_t *game)
{
    element_t *tmp = game->npcs.start.next;

    for (int i = 0; i < game->npcs.length; ++i) {
        if (game->map.id == ((npc_t *)tmp->data)->config->map_id) {
            update_npc(game, (npc_t *)tmp->data);
            draw_npc(game, (npc_t *)tmp->data);
        }
        tmp = tmp->next;
    }
}

static void display_player(game_data_t *game)
{
    update_player_engine(game->player);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
}

static void display_map(game_data_t *game)
{
    sfSprite *sp_map = get_sprite(game, game->map.map);

    if (sp_map == NULL)
        return;
    sfRenderWindow_drawSprite(game->window, sp_map, NULL);
}

static void apply_shader(game_data_t *game)
{
    sfVector2u resolution = sfRenderWindow_getSize(game->window);
    sfTexture *texture = sfTexture_create(WINDOW_WIDTH, WINDOW_HEIGHT);
    sfSprite *sprite = sfSprite_create();
    sfShader *shader = game->assets.shaders[SH_MAIN_DARKNESS];
    sfRenderStates states = { .blendMode = sfBlendAlpha, .shader = shader,
        .texture = texture, .transform = sfTransform_Identity };

    if (shader == NULL || texture == NULL || sprite == NULL)
        return;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, game->view_pos);
    sfSprite_setOrigin(sprite, (sfVector2f){WINDOW_WIDTH / 2,
        WINDOW_HEIGHT / 2});
    sfShader_setVec2Uniform(shader, "resolution",
        (sfVector2f){resolution.x, resolution.y});
    sfShader_setFloatUniform(shader, "time",
        sfTime_asSeconds(sfClock_getElapsedTime(game->clock)));
    sfRenderWindow_drawSprite(game->window, sprite, &states);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

static void display_overlay(game_data_t *game)
{
    sfVector2f relativepos = {game->view_pos.x + WINDOW_WIDTH / 2,
        game->view_pos.y - WINDOW_HEIGHT / 2};
    sfText *passiv;
    sfSprite *sp_health = get_sprite(game, SP_HEALTH2);
    sfText *health;
    char buffer[10];

    relativepos.y += 30;
    if (game->is_passive) {
        relativepos.x -= 240;
        passiv = set_text(game, "PASSIVE MODE [W]", 22, relativepos);
    } else {
        relativepos.x -= 240;
        passiv = set_text(game, "HOSTILE MODE [W]", 22, relativepos);
    }
    sfRenderWindow_drawText(game->window, passiv, NULL);
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
    sfText_destroy(passiv);
    sfText_destroy(health);
}

static void check_gameplay_keys(game_data_t *game)
{
    if (is_key_pressed(game, Inventory))
        change_game_mode(game, INVENTORY);
    if (is_key_pressed(game, Echap))
        change_game_mode(game, PAUSE);
    if (is_key_pressed(game, Interact))
        game->is_passive = !game->is_passive;
}

void process_playing_gameplay(game_data_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->player->clock);
    map_id_t map_id = game->map.id;

    if (is_key_pressed(game, Reset)) {
        map_id = (map_id + 1) % 3;
        set_map(game, map_id);
    }
    sfRenderWindow_setView(game->window, game->game_view);
    sfClock_restart(game->player->clock);
    update_player(game, time);
    check_gameplay_keys(game);
    display_map(game);
    display_player(game);
    display_enemies(game);
    display_npcs(game);
    apply_shader(game);
    display_overlay(game);
}
