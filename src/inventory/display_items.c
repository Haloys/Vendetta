/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** display_items
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

void display_item_images(game_data_t *game, sfRectangleShape **grid)
{
    sfVector2f pos = {0};
    sfSprite *sprite = NULL;
    inventory_slot_t *slot = NULL;
    char *qty_txt = malloc(3);
    char *weight_txt = malloc(6);

    for (int i = 0; i < COUNT; i++) {
        slot = &game->player_data->inventory->slots[i];
        if (slot->item != NULL) {
            sprintf(qty_txt, "x%d", slot->quantity);
            sprintf(weight_txt, "%.1fkg", slot->weight);
            pos = sfRectangleShape_getPosition(grid[i]);
            display_inv_text(game, pos, qty_txt, weight_txt);
            sprite = get_sprite(game, slot->item->sprite_id);
            sfSprite_setPosition(sprite, (sfVector2f){pos.x + 25, pos.y + 35});
            sfRenderWindow_drawSprite(game->window, sprite, NULL);
        }
    }
}
