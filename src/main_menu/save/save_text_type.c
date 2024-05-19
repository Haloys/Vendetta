/*
** EPITECH PROJECT, 2024
** Vendetta / Main Menu / Save
** File description:
** Save Text Type
*/

#include "my_game.h"
#include "save.h"
#include "main_menu.h"

#include <stdio.h>
#include <string.h>

static void create_text(game_data_t *game, sfText **text)
{
    *text = sfText_create();
    sfText_setFont(*text, game->font);
    sfText_setCharacterSize(*text, 28);
    sfText_setPosition(*text, (sfVector2f){437, 442});
}

static void create_rectangle_save(sfRectangleShape **rect)
{
    *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(*rect, (sfVector2f){427, 421});
    sfRectangleShape_setSize(*rect, (sfVector2f){1000, 80});
    sfRectangleShape_setFillColor(*rect, FILL_COLOR);
    sfRectangleShape_setOutlineThickness(*rect, 1.0);
    sfRectangleShape_setOutlineColor(*rect, OUTLINE_COLOR);
}

static void handle_text_entered_event(sfEvent event, char *input,
    size_t input_size, game_ui_t *game_ui)
{
    size_t len = strlen(input);
    sfFloatRect text_bounds = sfText_getGlobalBounds(game_ui->text);
    sfFloatRect rectangle_bounds =
        sfRectangleShape_getGlobalBounds(game_ui->rect);

    if (event.text.unicode < 32 || event.text.unicode > 126)
        return;
    if (len < input_size - 1) {
        input[len] = event.text.unicode;
        input[len + 1] = '\0';
    }
    sfText_setString(game_ui->text, input);
    if (text_bounds.width > rectangle_bounds.width - 40) {
        input[len] = '\0';
        sfText_setString(game_ui->text, input);
    }
    printf("Number of characters: %ld\n", strlen(input));
}

static void handle_key_load_save(sfEvent event,
    char *input, game_ui_t *game_ui)
{
    size_t len = strlen(input);

    if (event.key.code == sfKeyBack) {
        if (len > 0) {
            input[len - 1] = '\0';
            sfText_setString(game_ui->text, input);
        }
    }
}

static void handle_mouse_load_save(game_data_t *game, game_ui_t *game_ui)
{
    handle_valid_button_click(game, game_ui);
    handle_cancel_button_click(game, game_ui);
}

static void handle_save_evt(game_data_t *game, sfEvent event,
    game_ui_t *game_ui)
{
    if (event.type == sfEvtTextEntered)
        handle_text_entered_event(event, game_ui->input,
            game_ui->input_size, game_ui);
    if (event.type == sfEvtMouseButtonPressed)
        handle_mouse_load_save(game, game_ui);
    if (event.type == sfEvtKeyPressed)
        handle_key_load_save(event, game_ui->input, game_ui);
}

static void handle_game_ui(game_data_t *game, game_ui_t *game_ui)
{
    sfEvent event;

    while (game->state == SAVE) {
        while (sfRenderWindow_pollEvent(game->window, &event))
            handle_save_evt(game, event, game_ui);
        update_valid_button_color(game, game_ui);
        sfRenderWindow_clear(game->window, sfBlack);
        basic_design(game);
        draw_load_save_texts(game);
        sfRenderWindow_drawRectangleShape(game->window, game_ui->rect, NULL);
        sfRenderWindow_drawRectangleShape(game->window, game_ui->valid_b,
            NULL);
        sfRenderWindow_drawRectangleShape(game->window, game_ui->cancel_b,
            NULL);
        sfRenderWindow_drawText(game->window, game_ui->text, NULL);
        sfRenderWindow_drawText(game->window, game_ui->validate_text, NULL);
        sfRenderWindow_drawText(game->window, game_ui->cancel_text, NULL);
        sfRenderWindow_display(game->window);
    }
}

static void load_save(game_data_t *game)
{
    game_ui_t game_ui;

    game_ui.input_size = sizeof(game_ui.input);
    create_text(game, &game_ui.text);
    create_validate_text(game, &game_ui.validate_text);
    create_cancel_text(game, &game_ui.cancel_text);
    create_rectangle_save(&game_ui.rect);
    create_validate_button(&game_ui);
    create_cancel_button(&game_ui);
    handle_game_ui(game, &game_ui);
    sfText_destroy(game_ui.text);
    sfText_destroy(game_ui.cancel_text);
    sfRectangleShape_destroy(game_ui.rect);
    sfRectangleShape_destroy(game_ui.valid_b);
    sfRectangleShape_destroy(game_ui.cancel_b);
}

void basic_save(game_data_t *game)
{
    load_save(game);
}
