/*
** EPITECH PROJECT, 2024
** Vendetta / Inventory
** File description:
** Inventory
*/

#include <stdlib.h>
#include <stdio.h>

#include "my_game.h"
#include "inventory.h"

static void draw_inventory_grid(game_data_t *game, sfRectangleShape ***grid)
{
    sfVector2f pos = {220, 280};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    for (size_t i = 0; i < HEIGHT; i++) {
        for (size_t j = 0; j < WIDTH; j++) {
            (*grid)[i * WIDTH + j] = sfRectangleShape_create();
            sfRectangleShape_setPosition((*grid)[i * WIDTH + j],
            (sfVector2f){pos.x + j * (SIZE + GAP), pos.y + i * (SIZE + GAP)});
            sfRectangleShape_setSize((*grid)[i * WIDTH + j], (sfVector2f) {
                SIZE, SIZE
            });
            handle_hover((*grid)[i * WIDTH + j], mouse_pos);
            sfRectangleShape_setOutlineThickness((*grid)[i * WIDTH + j], 2);
            sfRectangleShape_setFillColor((*grid)[i * WIDTH + j], SQUARE_BG);
            sfRenderWindow_drawRectangleShape(game->window,
                (*grid)[i * WIDTH + j], NULL);
        }
    }
}

static void draw_progbar(game_data_t *game)
{
    sfRectangleShape *weight_bg = sfRectangleShape_create();
    sfRectangleShape *weight_bar = sfRectangleShape_create();
    int width = game->player->inventory->total_weight * 600 / 25;

    sfRectangleShape_setPosition(weight_bg, (sfVector2f){220, 240});
    sfRectangleShape_setPosition(weight_bar, (sfVector2f){220, 240});
    sfRectangleShape_setSize(weight_bg, (sfVector2f){600, 10});
    sfRectangleShape_setSize(weight_bar, (sfVector2f){width, 10});
    sfRectangleShape_setFillColor(weight_bg, SQUARE_BG);
    sfRectangleShape_setFillColor(weight_bar, BORDER_HOVER);
    sfRenderWindow_drawRectangleShape(game->window, weight_bg, NULL);
    sfRenderWindow_drawRectangleShape(game->window, weight_bar, NULL);
    sfRectangleShape_destroy(weight_bg);
    sfRectangleShape_destroy(weight_bar);
}

static void draw_title_and_progbar(game_data_t *game)
{
    sfText *title = set_text(game, "CAPACITY", 26, (sfVector2f){220, 190});
    sfText *subtitle = NULL;
    char *total_weight = NULL;

    sfRenderWindow_drawSprite(game->window, get_sprite(game, SP_MAIN_BG),
        NULL);
    sfRenderWindow_drawSprite(game->window, get_sprite(game, SP_MAN_SKIN),
        NULL);
    asprintf(&total_weight, "%.2f / 25.00 KG",
    game->player->inventory->total_weight);
    if (game->player->inventory->total_weight < 10.f)
        subtitle = set_text(game, total_weight, 20, (sfVector2f){670, 190});
    else
        subtitle = set_text(game, total_weight, 20, (sfVector2f){660, 190});
    sfRenderWindow_drawText(game->window, title, NULL);
    sfRenderWindow_drawText(game->window, subtitle, NULL);
    draw_progbar(game);
    sfText_destroy(title);
    sfText_destroy(subtitle);
    free(total_weight);
}

static void draw_action_buttons(game_data_t *game, sfRectangleShape ***grid)
{
    sfText *use_text = set_text(game, "USE", 20, (sfVector2f){318, 927});
    sfText *del_text = set_text(game, "TRASH", 20, (sfVector2f){668, 927});

    (*grid)[29] = create_rectangle(game, (sfVector2f){220, 915}, 235, 50);
    (*grid)[30] = create_rectangle(game, (sfVector2f){585, 915}, 235, 50);
    sfRenderWindow_drawText(game->window, use_text, NULL);
    sfRenderWindow_drawText(game->window, del_text, NULL);
    sfText_destroy(use_text);
    sfText_destroy(del_text);
}

static void draw_statistics_txt(game_data_t *game, char *health, char *armor,
    char *speed)
{
    sfText *health_txt = set_text(game, health, 20, (sfVector2f){1640, 642});
    sfText *armor_txt = set_text(game, armor, 20, (sfVector2f){1640, 712});
    sfText *speed_txt = set_text(game, speed, 20, (sfVector2f){1640, 852});

    sfRenderWindow_drawText(game->window, health_txt, NULL);
    sfRenderWindow_drawText(game->window, armor_txt, NULL);
    sfRenderWindow_drawText(game->window, speed_txt, NULL);
    sfText_destroy(health_txt);
    sfText_destroy(armor_txt);
    sfText_destroy(speed_txt);
    free(health);
    free(armor);
    free(speed);
}

static void draw_statistics(game_data_t *game)
{
    char *health = NULL;
    char *armor = NULL;
    char *speed = NULL;
    char *attack = NULL;
    sfText *attack_txt = NULL;

    asprintf(&health, "%d", game->player->max_health);
    asprintf(&armor, "%d", game->player->armor);
    asprintf(&speed, "%d", game->player->speed);
    asprintf(&attack, "%d", game->player->attack);
    if (health == NULL || armor == NULL || speed == NULL || attack == NULL)
        return;
    attack_txt = set_text(game, attack, 20, (sfVector2f){1640, 782});
    sfRenderWindow_drawSprite(game->window, get_sprite(game, SP_STATS), NULL);
    sfRenderWindow_drawText(game->window, attack_txt, NULL);
    draw_statistics_txt(game, health, armor, speed);
    sfText_destroy(attack_txt);
    free(attack);
}

static void draw_equipment_slots_txt(game_data_t *game)
{
    sfText *helmet_txt = set_text(game, "HELMET", 14, (sfVector2f){1010, 255});
    sfText *armor_txt = set_text(game, "ARMOR", 14, (sfVector2f){1010, 415});
    sfText *shoes_txt = set_text(game, "SHOES", 14, (sfVector2f){1010, 755});
    sfText *weapon_txt = set_text(game, "WEAPON", 14, (sfVector2f){1160, 415});

    sfRenderWindow_drawText(game->window, helmet_txt, NULL);
    sfRenderWindow_drawText(game->window, armor_txt, NULL);
    sfRenderWindow_drawText(game->window, shoes_txt, NULL);
    sfRenderWindow_drawText(game->window, weapon_txt, NULL);
    sfText_destroy(helmet_txt);
    sfText_destroy(armor_txt);
    sfText_destroy(shoes_txt);
    sfText_destroy(weapon_txt);
}

static void draw_equipment_slots(game_data_t *game, sfRectangleShape ***grid)
{
    (*grid)[25] = create_rectangle(game, (sfVector2f){1010, 280}, SIZE, SIZE);
    (*grid)[26] = create_rectangle(game, (sfVector2f){1010, 440}, SIZE, SIZE);
    (*grid)[27] = create_rectangle(game, (sfVector2f){1010, 780}, SIZE, SIZE);
    (*grid)[28] = create_rectangle(game, (sfVector2f){1160, 440}, SIZE, SIZE);
    draw_equipment_slots_txt(game);
}

static void destroy_grid(sfRectangleShape ***grid)
{
    for (size_t i = 0; i < 31; i++) {
        sfRectangleShape_destroy((*grid)[i]);
    }
}

void basic_inventory(game_data_t *game)
{
    sfRectangleShape **grid = malloc(31 * sizeof(sfRectangleShape *));

    game->last_state = INVENTORY;
    if (grid == NULL)
        return;
    draw_title_and_progbar(game);
    draw_navbar(game);
    draw_active_navbar_line(game, 315.0f, 300.0f);
    draw_inventory_grid(game, &grid);
    draw_action_buttons(game, &grid);
    draw_statistics(game);
    draw_equipment_slots(game, &grid);
    display_item_images(game, grid);
    handle_items_hover_label(game, grid);
    handle_drag_and_drop(game, grid);
    destroy_grid(&grid);
    free(grid);
}
