/*
** EPITECH PROJECT, 2024
** Vendetta / Main Menu / Save
** File description:
** Save UI
*/

#include "my_game.h"
#include "save.h"

void draw_load_save_texts(game_data_t *game)
{
    sprite_id_t elements[] = {SP_LOAD_SAVE_HELP};
    int element_count = 1;
    sfSprite *sprites[element_count];

    for (int i = 0; i < element_count; i++) {
        sprites[i] = get_sprite(game, elements[i]);
    }
    for (int i = 0; i < element_count; i++) {
        sfRenderWindow_drawSprite(game->window, sprites[i], NULL);
    }
}

void create_cancel_text(game_data_t *game, sfText **text)
{
    *text = set_text(game, "CANCEL", 20, (sfVector2f){1049, 558});
}

void create_validate_text(game_data_t *game, sfText **text)
{
    *text = set_text(game, "VALIDATE", 20, (sfVector2f){780, 558});
}

void create_validate_button(game_ui_t *game_ui)
{
    game_ui->valid_b = sfRectangleShape_create();
    sfRectangleShape_setPosition(game_ui->valid_b,
        (sfVector2f){713, 545});
    sfRectangleShape_setSize(game_ui->valid_b, (sfVector2f){235, 50});
    sfRectangleShape_setFillColor(game_ui->valid_b, FILL_COLOR);
    sfRectangleShape_setOutlineThickness(game_ui->valid_b, 1.0);
    sfRectangleShape_setOutlineColor(game_ui->valid_b, OUTLINE_COLOR);
}

void create_cancel_button(game_ui_t *game_ui)
{
    game_ui->cancel_b = sfRectangleShape_create();
    sfRectangleShape_setPosition(game_ui->cancel_b,
        (sfVector2f){971, 544});
    sfRectangleShape_setSize(game_ui->cancel_b, (sfVector2f){235, 50});
    sfRectangleShape_setFillColor(game_ui->cancel_b, FILL_COLOR);
    sfRectangleShape_setOutlineThickness(game_ui->cancel_b, 1.0);
    sfRectangleShape_setOutlineColor(game_ui->cancel_b, OUTLINE_COLOR);
}
