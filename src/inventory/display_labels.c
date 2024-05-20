/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** display_labels
*/

#include <stdlib.h>
#include <stdio.h>

#include "my_game.h"
#include "inventory.h"

static void display_values(game_data_t *game, sfText *txt_1, sfText *txt_2)
{
    sfRenderWindow_drawText(game->window, txt_1, NULL);
    sfRenderWindow_drawText(game->window, txt_2, NULL);
    sfText_destroy(txt_1);
    sfText_destroy(txt_2);
}

static void display_item_label(game_data_t *game, sfVector2f pos,
    int i)
{
    sfRectangleShape *bg = sfRectangleShape_create();
    sfText *label = set_text(game,
        game->player->inventory->slots[i].item->label, 14,
        (sfVector2f){pos.x + 35, pos.y - 5});
    sfText *is_usable = set_text(game, "Usable :", 14,
        (sfVector2f){pos.x + 35, pos.y + 20});
    sfText *is_equipable = set_text(game, "Equipable :", 14,
        (sfVector2f){pos.x + 35, pos.y + 40});

    sfRectangleShape_setPosition(bg, (sfVector2f){pos.x + 20, pos.y - 15});
    sfRectangleShape_setSize(bg, (sfVector2f){200, 150});
    sfRectangleShape_setFillColor(bg, sfColor_fromRGB(18, 23, 36));
    sfRenderWindow_drawRectangleShape(game->window, bg, NULL);
    sfRenderWindow_drawText(game->window, label, NULL);
    sfRenderWindow_drawText(game->window, is_usable, NULL);
    sfRenderWindow_drawText(game->window, is_equipable, NULL);
    sfText_destroy(label);
    sfText_destroy(is_usable);
    sfText_destroy(is_equipable);
    sfRectangleShape_destroy(bg);
}

static void display_icons_sprites(game_data_t *game, sfVector2f pos)
{
    int base_id = SP_HEALTH_ICON;
    sfSprite *sprite = get_sprite(game, base_id);
    sfVector2f pos_sprite = {pos.x + 35, pos.y + 75};
    sfVector2f pos_sprite2 = {pos.x + 120, pos.y + 75};

    for (int i = 0; i < 2; i++) {
        sfSprite_setPosition(sprite, pos_sprite);
        sfRenderWindow_drawSprite(game->window, sprite, NULL);
        base_id++;
        sprite = get_sprite(game, base_id);
        pos_sprite.y += 30;
    }
    for (int i = 0; i < 2; i++) {
        sfSprite_setPosition(sprite, pos_sprite2);
        sfRenderWindow_drawSprite(game->window, sprite, NULL);
        base_id++;
        sprite = get_sprite(game, base_id);
        pos_sprite2.y += 30;
    }
}

static void disp_stat_values_2(game_data_t *game, sfVector2f pos, item_t *item)
{
    char *speed = NULL;
    char *damage = NULL;
    sfText *d_txt = NULL;
    sfText *s_txt = NULL;

    if (item->speed >= 0)
        asprintf(&speed, "+ %d", item->speed);
    else
        asprintf(&speed, "- %d", item->speed * -1);
    if (item->damage >= 0)
        asprintf(&damage, "+ %d", item->damage);
    else
        asprintf(&damage, "- %d", item->damage * -1);
    if (speed == NULL || damage == NULL)
        return;
    d_txt = set_text(game, damage, 14, (sfVector2f){pos.x + 150, pos.y + 73});
    s_txt = set_text(game, speed, 14, (sfVector2f){pos.x + 150, pos.y + 103});
    display_values(game, d_txt, s_txt);
    free(speed);
    free(damage);
}

static void disp_stats_values(game_data_t *game, sfVector2f pos, item_t *item)
{
    char *health = NULL;
    char *armor = NULL;
    sfText *h_txt = NULL;
    sfText *a_txt = NULL;

    if (item->health >= 0)
        asprintf(&health, "+ %d", item->health);
    else
        asprintf(&health, "- %d", item->health);
    if (item->armor >= 0)
        asprintf(&armor, "+ %d", item->armor);
    else
        asprintf(&armor, "- %d", item->armor);
    h_txt = set_text(game, health, 14, (sfVector2f){pos.x + 60, pos.y + 73});
    a_txt = set_text(game, armor, 14, (sfVector2f){pos.x + 60, pos.y + 103});
    display_values(game, h_txt, a_txt);
    disp_stat_values_2(game, pos, item);
    free(health);
    free(armor);
}

static void display_specs(game_data_t *game, sfVector2f pos, int i)
{
    item_t *item = game->player->inventory->slots[i].item;
    sfText *is_usable_txt = set_text(game, GET_SENTENCE(item->is_usable), 14,
        (sfVector2f){pos.x + 120, pos.y + 20});
    sfText *is_equipable_txt = set_text(game, GET_SENTENCE(item->is_equipable),
        14, (sfVector2f){pos.x + 120, pos.y + 40});

    if (item->is_usable)
        sfText_setColor(is_usable_txt, sfColor_fromRGB(51, 217, 122));
    else
        sfText_setColor(is_usable_txt, sfColor_fromRGB(255, 111, 111));
    if (item->is_equipable)
        sfText_setColor(is_equipable_txt, sfColor_fromRGB(51, 217, 122));
    else
        sfText_setColor(is_equipable_txt, sfColor_fromRGB(255, 111, 111));
    display_values(game, is_usable_txt, is_equipable_txt);
    disp_stats_values(game, pos, item);
}

void handle_items_hover_label(game_data_t *game, sfRectangleShape **grid)
{
    sfVector2f mouse_pos = game->mouse_pos;
    sfFloatRect bounds = {0};

    for (size_t i = 0; i < 29; i++) {
        bounds = sfRectangleShape_getGlobalBounds(grid[i]);
        if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y) &&
            i < 29 && game->player->inventory->slots[i].item != NULL) {
            display_item_label(game, mouse_pos, i);
            display_icons_sprites(game, mouse_pos);
            display_specs(game, mouse_pos, i);
        }
    }
}
