/*
** EPITECH PROJECT, 2024
** my_game.h
** File description:
** dd
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

typedef enum state_e {
    LOADING_SCREEN,
    MAIN_MENU,
    SETTINGS_VIDEO,
    SETTINGS_CONTROLS,
    SETTINGS_AUDIO,
    HELP,
    PLAYING,
    PAUSE,
    INVENTORY,
} state_t;

typedef struct game_assets_s {
    sfTexture *texture[IMAGE_COUNT];
    sfSprite *sprite[SPRITE_COUNT];
    sfSoundBuffer *sound[SOUND_COUNT];
    sfMusic *music[MUSIC_COUNT];
} game_assets_t;

#define NAVBAR_TEXT_COLOR sfColor_fromRGB(197, 197, 197)
#define NAVBAR_LINE_COLOR sfColor_fromRGBA(255, 255, 255, 76)
#define ACTIVE_NAVBAR_TEXT_COLOR sfColor_fromRGB(51, 217, 122)

typedef struct navbar_element_s {
    const char *label;
    sprite_id_t icon;
    sfVector2f position;
    sfVector2f size;
    state_t target_state;
} navbar_element_t;

typedef struct settings_navbar_element_s {
    const char *label;
    sfVector2f position;
    sfVector2f size;
} settings_navbar_element_t;

typedef struct text_draw_info_settings_s {
    sfVector2f text_position;
    sfColor hover_color;
} text_draw_info_settings_t;

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

typedef struct slider_s {
    sfRectangleShape *bg_music;
    sfCircleShape *thumb_music;
    sfRectangleShape *bg_global;
    sfCircleShape *thumb_global;
    sfRectangleShape *bg_ambient;
    sfCircleShape *thumb_ambient;
    float min_music;
    float max_music;
    float min_global;
    float max_global;
    float min_ambient;
    float max_ambient;
    sfVector2f pos_music;
    sfVector2f pos_global;
    sfVector2f pos_ambient;
    float value_music;
    float value_global;
    float value_ambient;
} slider_t;

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
    slider_t slider;
} game_data_t;

void draw_navbar(game_data_t *game);
void draw_active_navbar_line(game_data_t *game,
    float pos_x, float size_x);


int print_game_help(void);

void new_set_text(game_data_t *game, char *txt, int size, sfVector2f pos);

int init_game(game_data_t *game);
void start_game_loop(game_data_t *game);
void process_events(game_data_t *game);
void process_game_loop(game_data_t *game);
int init_assets(game_data_t *game);
int destroy_game_data(game_data_t *game, int code);
sfSprite *get_sprite(game_data_t *game, sprite_id_t id);
int is_rect_click(sfFloatRect const *rect, sfVector2f mouse);
int play_sound(game_data_t *game, sound_id_t id);
void launch_loading(game_data_t *game);
void basic_menu(game_data_t *game);
void set_screen_text(game_data_t *game);
void set_fps_text(game_data_t *game);
void load_arrow(game_data_t *game);
void set_screen_size(game_data_t *game);
void set_reso_text(game_data_t *game);
void set_reso(game_data_t *game);
void set_utils_text(game_data_t *game);
void draw_everything_sound(game_data_t *game);
void init_slider_music(slider_t *slider, sfVector2f position,
    float min, float max);
void init_slider_global(slider_t *slider, sfVector2f position,
    float min, float max);
void init_slider_ambient(slider_t *slider, sfVector2f position,
    float min, float max);
void update_slider_ambient(game_data_t *const game, slider_t *slider);
void update_slider_music(game_data_t *const game, slider_t *slider);
void update_slider_global(game_data_t *const game, slider_t *slider);
void draw_slider(slider_t *sl, game_data_t *game);


// Score manager
void start_music(game_assets_t *assets, music_id_t id);
sfText *set_text(game_data_t *game, char *txt, int size, sfVector2f pos);

// Inventory
void basic_inventory(game_data_t *game);

#define ICON_PATH "assets/images/game_icon/icon.png"

#endif /* MY_GAME_H */
