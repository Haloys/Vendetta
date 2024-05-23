/*
** EPITECH PROJECT, 2024
** Vendetta / Main Menu
** File description:
** Main Menu
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "my_game.h"

void draw_active_navbar_line(game_data_t *game,
    float pos_x, float size_x)
{
    sfRectangleShape *line = sfRectangleShape_create();

    sfRectangleShape_setPosition(line, (sfVector2f){pos_x, 102.0f});
    sfRectangleShape_setSize(line, (sfVector2f){size_x, 4.0f});
    sfRectangleShape_setFillColor(line, ACTIVE_NAVBAR_TEXT_COLOR);
    sfRenderWindow_drawRectangleShape(game->window, line, NULL);
    sfRectangleShape_destroy(line);
}

void basic_menu(game_data_t *game)
{
    sprite_id_t elements[] = {SP_MAIN_BG, SP_VENDETTA_MENU};
    size_t element_count = 2;

    for (size_t i = 0; i < element_count; i++) {
        sfRenderWindow_drawSprite(game->window,
            get_sprite(game, elements[i]), NULL);
    }
    draw_navbar(game);
}

static void draw_game_slot(game_data_t *game, float rect_x, float rect_y,
    int slot_index)
{
    bool is_hovered = game->hover_slot_array[slot_index];
    sfRectangleShape *slot = sfRectangleShape_create();
    sfColor hover_color = is_hovered ? sfColor_fromRGB(51, 217, 122)
    : sfColor_fromRGBA(255, 255, 255, 128);

    sfRectangleShape_setPosition(slot, (sfVector2f){rect_x, rect_y});
    sfRectangleShape_setSize(slot, (sfVector2f){452, 629});
    sfRectangleShape_setFillColor(slot, sfColor_fromRGBA(255, 255, 255, 0));
    sfRectangleShape_setOutlineColor(slot, hover_color);
    sfRectangleShape_setOutlineThickness(slot, 1.0f);
    sfRenderWindow_drawRectangleShape(game->window, slot, NULL);
    sfRectangleShape_destroy(slot);
}

void setup_game_slots(game_data_t *game)
{
    draw_game_slot(game, 149, 241, 0);
    draw_game_slot(game, 727, 241, 1);
    draw_game_slot(game, 1321, 241, 2);
}

static void draw_load_save_button(game_data_t *game)
{
    sfRectangleShape *saveButton = sfRectangleShape_create();
    sfVector2f textPosition = {198, 161};
    sfText *saveText = set_text(game, "LOAD A SAVE", 20, textPosition);
    sfColor fill_color;
    sfColor outline_color;

    determine_button_colors(game, &fill_color, &outline_color);
    sfRectangleShape_setPosition(saveButton, (sfVector2f){147, 148});
    sfRectangleShape_setSize(saveButton, (sfVector2f){235, 50});
    sfRectangleShape_setFillColor(saveButton, fill_color);
    sfRectangleShape_setOutlineColor(saveButton, outline_color);
    sfRectangleShape_setOutlineThickness(saveButton, 1.0f);
    sfRenderWindow_drawRectangleShape(game->window, saveButton, NULL);
    sfRectangleShape_destroy(saveButton);
    sfRenderWindow_drawText(game->window, saveText, NULL);
    sfText_destroy(saveText);
}

static void draw_load_save(game_data_t *game)
{
    sprite_id_t elements[] = {SP_SAVE_1, SP_SAVE_2, SP_SAVE_3};
    int element_count = sizeof(elements) / sizeof(elements[0]);
    sfSprite *sprites[element_count];

    for (int i = 0; i < element_count; i++) {
        sprites[i] = get_sprite(game, elements[i]);
    }
    for (int i = 0; i < element_count; i++) {
        if (game->is_sprite_displayed &&
        game->save_games[i].save_name[0] != '\0') {
            sfRenderWindow_drawSprite(game->window, sprites[i], NULL);
            draw_bottom_part(game, i);
        }
    }
}

static void draw_empty_slots(game_data_t *game)
{
    sfVector2f positions[] = {
        {227.0f, 311.0f},
        {813.0f, 311.0f},
        {1400.0f, 311.0f}
    };
    int position_count = sizeof(positions) / sizeof(positions[0]);
    sfSprite *sprite = get_sprite(game, SP_EMPTY_SLOT);

    for (int i = 0; i < position_count; i++) {
        if (game->save_games[i].save_name[0] == '\0') {
            sfSprite_setPosition(sprite, positions[i]);
            sfRenderWindow_drawSprite(game->window, sprite, NULL);
        }
    }
}

void basic_play(game_data_t *game)
{
    game->last_state = MAIN_MENU;
    basic_menu(game);
    draw_active_navbar_line(game, 80.0f, 210.0f);
    draw_load_save_button(game);
    setup_game_slots(game);
    draw_empty_slots(game);
    draw_load_save(game);
    count_existing_saves(game);
}
