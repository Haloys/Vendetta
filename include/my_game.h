/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** My Game
*/

#ifndef MY_GAME_H
    #define MY_GAME_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Audio.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <stdbool.h>

    #include "resources.h"
    #include "inventory.h"
    #include "game_utils.h"
    #include "state.h"
    #include "navbar.h"

typedef struct game_assets_s {
    sfTexture *texture[IMAGE_COUNT];
    sfSprite *sprite[SPRITE_COUNT];
    sfSoundBuffer *sound[SOUND_COUNT];
    sfMusic *music[MUSIC_COUNT];
} game_assets_t;

typedef struct player_data_s {
    inventory_t *inventory;
    int max_health;
    int health;
    int speed;
    int armor;
    int attack;
    int item_health;
    int item_speed;
    int item_armor;
    int item_attack;
} player_data_t;

typedef struct game_data_s {
    char name[10];
    sfVideoMode video_mode;
    sfRenderWindow *window;
    state_t state;
    sfClock *clock;
    sfCursor *cursor;
    game_assets_t assets;
    sfFont *font;
    int fps;
    sfClock *fps_clock;
    sfClock *time;
    sfText *help_text;
    float speed;
    sfUint8 *pixels;
    int mouse_x;
    int mouse_y;
    bool is_fullscreen;
    bool hover_save_button;
    bool hover_array[4];
    bool hover_slot_array[3];
    bool is_navbar_visible;
    sfVector2f mouse_pos;
    player_data_t *player_data;
} game_data_t;

// Init
int print_game_help(void);
int init_game(game_data_t *game);
int init_assets(game_data_t *game);
void start_game_loop(game_data_t *game);
void set_mouse_pos(game_data_t *game);

// Events
void process_events(game_data_t *game);

// Main Loop
void process_game_loop(game_data_t *game);
void launch_loading(game_data_t *game);

// Free
int destroy_game_data(game_data_t *game, int code);

// Utils
sfSprite *get_sprite(game_data_t *game, sprite_id_t id);
int is_rect_click(sfFloatRect const *rect, sfVector2f mouse);
int play_sound(game_data_t *game, sound_id_t id);
void new_set_text(game_data_t *game, char *txt, int size, sfVector2f pos);
sfText *set_text(game_data_t *game, char *txt, int size, sfVector2f pos);
void start_music(game_assets_t *assets, music_id_t id);

// Settings
void set_screen_text(game_data_t *game);
void set_fps_text(game_data_t *game);
void load_arrow(game_data_t *game);
void set_screen_size(game_data_t *game);
void set_reso_text(game_data_t *game);
void set_reso(game_data_t *game);
void set_utils_text(game_data_t *game);
void arrow_l_fps(game_data_t *game);

// Inventory
void basic_inventory(game_data_t *game);

#define ICON_PATH "assets/images/game_icon/icon.png"

#endif /* MY_GAME_H */
