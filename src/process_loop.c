/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Process Loop
*/

#include "my_game.h"
#include "main_menu.h"
#include "gameplay.h"

const process_state_t process_state[] = {
    launch_loading,
    basic_play,
    basic_settings,
    draw_everything_control,
    draw_everything_sound,
    basic_help,
    process_playing_gameplay,
    basic_inventory,
    basic_save,
    npc_dialogues,
    display_skill_tree,
    display_sequence_click,
    display_barhit,
    display_first_book,
    display_second_book,
    display_third_book,
    display_ending_screen,
    display_game_over,
};

static void clean_sound(game_data_t *game)
{
    int saved_len = game->active_sounds.length;
    element_t *tmp = game->active_sounds.start.next;
    sfSound *sound = NULL;

    for (int i = 0; i < saved_len; ++i) {
        tmp = tmp->next;
        sound = (sfSound *)tmp->prev->data;
        if (sfSound_getStatus(sound) == sfStopped) {
            list_remove_element(&game->active_sounds, tmp->prev);
        }
    }
}

static void process_loop_update(game_data_t *game)
{
    clean_sound(game);
    for (size_t i = 0; i < STATE_COUNT; ++i) {
        if (game->state == i) {
            process_state[i](game);
            break;
        }
    }
}

void set_mouse_pos(game_data_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f map_pos = sfRenderWindow_mapPixelToCoords(game->window,
        mouse_pos, sfRenderWindow_getView(game->window));

    game->mouse_pos = map_pos;
}

void process_game_loop(game_data_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderTexture_clear(game->debug_overlay, sfTransparent);
    set_mouse_pos(game);
    process_events(game);
    process_loop_update(game);
    sfRenderWindow_display(game->window);
}
