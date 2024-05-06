/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel
** File description:
** main_menu
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_game.h"
#include "my.h"
#include "score.h"

void draw_active_navbar_line(game_data_t *game,
    float pos_x, float size_x)
{
    sfRectangleShape *line = sfRectangleShape_create();

    sfRectangleShape_setPosition(line, (sfVector2f){pos_x, 104.0f});
    sfRectangleShape_setSize(line, (sfVector2f){size_x, 2.0f});
    sfRectangleShape_setFillColor(line, ACTIVE_NAVBAR_TEXT_COLOR);
    sfRenderWindow_drawRectangleShape(game->window, line, NULL);
    sfRectangleShape_destroy(line);
}

void basic_menu(game_data_t *game)
{
    sprite_id_t elements[] = {SP_MAIN_BG, SP_VENDETTA_MENU};
    int element_count = 2;

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
    sfText *emptySlotText = set_text(game, "EMPTY SLOT", 26,
    (sfVector2f){rect_x + 146, rect_y + 73});
    sfText *newGameText = set_text(game, "CREATE A NEW GAME", 26,
    (sfVector2f){rect_x + 90, rect_y + 379});
    sfColor hover_color = is_hovered ? sfColor_fromRGB(51, 217, 122)
    : sfColor_fromRGBA(255, 255, 255, 128);

    sfRectangleShape_setPosition(slot, (sfVector2f){rect_x, rect_y});
    sfRectangleShape_setSize(slot, (sfVector2f){452, 629});
    sfRectangleShape_setFillColor(slot, sfColor_fromRGBA(255, 255, 255, 0));
    sfRectangleShape_setOutlineColor(slot, hover_color);
    sfRectangleShape_setOutlineThickness(slot, 1.0f);
    sfRenderWindow_drawRectangleShape(game->window, slot, NULL);
    sfRectangleShape_destroy(slot);
    sfRenderWindow_drawText(game->window, emptySlotText, NULL);
    sfRenderWindow_drawText(game->window, newGameText, NULL);
    sfText_destroy(emptySlotText);
    sfText_destroy(newGameText);
}

static void draw_game_slot_image(game_data_t *game, float x, float y)
{
    sfTexture* texture =
    sfTexture_createFromFile("assets/images/main_menu/game_slot.png", NULL);
    sfSprite* sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){x, y});
    sfSprite_setScale(sprite, (sfVector2f){1.0, 1.0});
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void setup_game_slots(game_data_t *game)
{
    draw_game_slot(game, 147, 241, 0);
    draw_game_slot(game, 734, 241, 1);
    draw_game_slot(game, 1321, 241, 2);
    draw_game_slot_image(game, 342.0f, 515.0f);
    draw_game_slot_image(game, 935.0f, 515.0f);
    draw_game_slot_image(game, 1522.0f, 515.0f);
}

static void draw_load_save_button(game_data_t *game)
{
    sfRectangleShape *saveButton = sfRectangleShape_create();
    sfVector2f textPosition = {198, 161};
    sfText *saveText = set_text(game, "LOAD A SAVE", 20, textPosition);
    sfColor fillColor = game->hover_save_button ?
    sfColor_fromRGBA(242, 115, 132, 128) :
    sfColor_fromRGBA(242, 115, 132, 51);
    sfColor outlineColor = game->hover_save_button ?
    sfColor_fromRGBA(242, 115, 132, 255) :
    sfColor_fromRGBA(242, 115, 132, 128);

    sfRectangleShape_setPosition(saveButton, (sfVector2f){147, 148});
    sfRectangleShape_setSize(saveButton, (sfVector2f){235, 50});
    sfRectangleShape_setFillColor(saveButton, fillColor);
    sfRectangleShape_setOutlineColor(saveButton, outlineColor);
    sfRectangleShape_setOutlineThickness(saveButton, 1.0f);
    sfRenderWindow_drawRectangleShape(game->window, saveButton, NULL);
    sfRectangleShape_destroy(saveButton);
    sfRenderWindow_drawText(game->window, saveText, NULL);
    sfText_destroy(saveText);
}

void basic_play(game_data_t *game)
{
    basic_menu(game);
    draw_active_navbar_line(game, 80.0f, 210.0f);
    draw_load_save_button(game);
    setup_game_slots(game);
}
