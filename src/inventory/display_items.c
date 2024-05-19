/*
** EPITECH PROJECT, 2024
** Vendetta / Inventory
** File description:
** Display Items
*/

#include <stdio.h>

#include "inventory.h"
#include "my_game.h"

static void display_inv_text(game_data_t *game, sfVector2f pos,
    char *qty, char *weight)
{
    sfText *wght_sp = NULL;
    sfText *qty_sp = NULL;

    qty_sp = set_text(game, qty, 14, (sfVector2f){pos.x + 7, pos.y + 10});
    wght_sp = set_text(game, weight, 14, (sfVector2f){pos.x + 65, pos.y + 10});
    sfRenderWindow_drawText(game->window, qty_sp, NULL);
    sfRenderWindow_drawText(game->window, wght_sp, NULL);
    sfText_destroy(qty_sp);
    sfText_destroy(wght_sp);
}

static void handle_sprite_selected(sfSprite *sprite, bool is_selected)
{
    sfColor color = sfSprite_getColor(sprite);

    color.a = is_selected ? 125 : 255;
    sfSprite_setColor(sprite, color);
}

void display_item_images(game_data_t *game, sfRectangleShape **grid)
{
    sfVector2f pos = {0};
    sfSprite *sprite = NULL;
    inventory_slot_t *slot = NULL;
    char *qty_txt = NULL;
    char *weight_txt = NULL;

    for (int i = 0; i < COUNT; i++) {
        slot = &game->player->inventory->slots[i];
        if (slot->item == NULL)
            continue;
        asprintf(&qty_txt, "x%d", slot->quantity);
        asprintf(&weight_txt, "%.1fkg", slot->weight);
        pos = sfRectangleShape_getPosition(grid[i]);
        display_inv_text(game, pos, qty_txt, weight_txt);
        sprite = get_sprite(game, slot->item->sprite_id);
        sfSprite_setPosition(sprite, (sfVector2f){pos.x + 25, pos.y + 35});
        handle_sprite_selected(sprite, slot->is_selected);
        sfRenderWindow_drawSprite(game->window, sprite, NULL);
    }
}
