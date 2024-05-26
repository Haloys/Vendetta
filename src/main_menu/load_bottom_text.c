/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** load_bottom_text
*/

#include "my_game.h"
#include "utils.h"
#include "gameplay.h"
#include "saves.h"

void draw_bottom_text(game_data_t *game, int i)
{
    sfVector2f text_position = {149.0, 757.0};
    sfText *text = set_text(game, game->save_games[i].save_name, 20,
        (sfVector2f){text_position.x + 20, text_position.y + 20});
    sfText *date = set_text(game, game->save_games[i].creation_date, 20,
        (sfVector2f){text_position.x + 20, text_position.y + 60});

    if (i == 1)
        text_position.x = 727.0;
    if (i == 2)
        text_position.x = 1321.0;
    sfText_setPosition(text, (sfVector2f){text_position.x + 20,
        text_position.y + 20});
    sfText_setPosition(date, (sfVector2f){text_position.x + 20,
        text_position.y + 65});
    sfRenderWindow_drawText(game->window, text, NULL);
    sfRenderWindow_drawText(game->window, date, NULL);
    sfText_destroy(text);
    sfText_destroy(date);
}

int remove_save(game_data_t *game, int i)
{
    if (game->save_games[i].save_path[0] == '\0')
        return 1;
    remove(game->save_games[i].save_path);
    game->save_games[i].save_name[0] = '\0';
    game->save_games[i].creation_date[0] = '\0';
    game->save_games[i].save_path[0] = '\0';
    return 0;
}

void handle_hover_and_action(game_data_t *game,
    sfRectangleShape *del_btn, int i)
{
    sfFloatRect del_bounds = sfRectangleShape_getGlobalBounds(del_btn);

    if (sfFloatRect_contains(&del_bounds, game->mouse_pos.x,
    game->mouse_pos.y) && game->state == MAIN_MENU) {
        sfRectangleShape_setFillColor(del_btn, RED_BTN_OUTLINE);
        sfRectangleShape_setOutlineColor(del_btn, RED_HOVER);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            remove_save(game, i - 1);
            play_sound(game, S_CLICK_SOUND);
        }
    }
}

void draw_delete_button(game_data_t *game, int i)
{
    sfVector2f pos = {149.0, 757.0};
    sfRectangleShape *del_btn = sfRectangleShape_create();
    sfText *del_text = set_text(game, "DELETE", 20, (sfVector2f){0, 0});

    pos.x = i == 1 ? 727.0 : pos.x;
    pos.x = i == 2 ? 1321.0 : pos.x;
    sfRectangleShape_setPosition(del_btn, (sfVector2f){pos.x + 280,
        pos.y + 31});
    sfText_setPosition(del_text, (sfVector2f){pos.x + 311, pos.y + 43});
    sfRectangleShape_setSize(del_btn, (sfVector2f){140, 50});
    sfRectangleShape_setFillColor(del_btn, RED_BTN_BG);
    sfRectangleShape_setOutlineColor(del_btn, RED_BTN_OUTLINE);
    sfRectangleShape_setOutlineThickness(del_btn, 2.0f);
    handle_hover_and_action(game, del_btn, i + 1);
    sfRenderWindow_drawRectangleShape(game->window, del_btn, NULL);
    sfRenderWindow_drawText(game->window, del_text, NULL);
    sfRectangleShape_destroy(del_btn);
    sfText_destroy(del_text);
}

void draw_bottom_part(game_data_t *game, int i)
{
    sfVector2f box_position = {149.0, 757.0};
    sfRectangleShape *placeholder = sfRectangleShape_create();

    if (i == 1)
        box_position.x = 727.0;
    if (i == 2)
        box_position.x = 1321.0;
    sfRectangleShape_setPosition(placeholder, box_position);
    sfRectangleShape_setSize(placeholder, (sfVector2f){452, 114});
    sfRectangleShape_setFillColor(placeholder, SQUARE_BG);
    sfRenderWindow_drawRectangleShape(game->window, placeholder, NULL);
    draw_bottom_text(game, i);
    draw_delete_button(game, i);
    sfRectangleShape_destroy(placeholder);
}
