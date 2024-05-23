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
    #include <stdio.h>

    #include "resources.h"
    #include "inventory.h"
    #include "game_utils.h"
    #include "state.h"
    #include "navbar.h"
    #include "save.h"
    #include "map.h"
    #include "list.h"
    #include "skill_tree.h"
    #include "minigame.h"
    #include "game_keys.h"
    #include "ending_screen.h"
    #include "notifications.h"
    #include "dialogues.h"
    #include "path_finding.h"

    #define ICON_PATH "assets/images/game_icon/icon.png"

    #define HOVER_FILL_COLOR sfColor_fromRGBA(51, 217, 122, 51)
    #define HOVER_OUTLINE_COLOR sfColor_fromRGBA(51, 217, 122, 128)
    #define FILL_COLOR sfColor_fromRGBA(255, 255, 255, 51)
    #define OUTLINE_COLOR sfColor_fromRGBA(255, 255, 255, 128)

typedef struct game_assets_s {
    sfTexture *texture[IMAGE_COUNT];
    sfSprite *sprite[SPRITE_COUNT];
    sfSound *sound[SOUND_COUNT];
    sfSoundBuffer *sound_buff[SOUND_COUNT];
    sfMusic *music[MUSIC_COUNT];
    sfShader *shaders[SHADER_COUNT];
} game_assets_t;

typedef struct player_data_s {
    int save_number;
    inventory_t *inventory;
    int max_health;
    int health;
    int speed;
    int armor;
    int attack;
    sfClock *clock;
    sfClock *anim_clock;
    float pspeed;
    sfVector2f direction;
    sfVector2f position;
    float rotation;
    float target_rot;
    game_sprite_t const *sprite_data;
    sfSprite *sprite;
    int current_lvl;
    int current_xp;
    skill_tree_t *skill_tree;
    int skill_points;
    bool is_playing;
    int npc_id;
    path_node_t *path;
} player_data_t;

typedef struct {
    float min;
    float max;
} min_max_t;

typedef struct {
    int sg_x;
    int sm_x;
    int sa_x;
    int clicked_rect_index;
    int clicked_rect;
    int clicked_control;
    bool is_fullscreen;
} settings_t;

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
    float speed;
    int mouse_x;
    int mouse_y;
    bool hover_save_button;
    bool hover_array[4];
    bool hover_slot_array[3];
    bool is_navbar_visible;
    int validation_count;
    bool is_sprite_displayed;
    sfVector2f mouse_pos;
    player_data_t *player;
    settings_t settings;
    sfImage *cols_map;
    long key_state;
    long key_change;
    long key_update;
    bool is_passive;
    sfView *game_view;
    sfView *menu_view;
    sfVector2f view_pos;
    float view_zoom;
    bool is_first;
    float target_zoom;
    map_config_t map;
    list_t enemies;
    list_t npcs;
    list_t entities;
    sfClock *animation_clock;
    sequence_click_t sequence;
    barhit_t barhit;
    sf_to_keybind_t keybinds[KEYBINDS_COUNT];
    state_t last_state;
    list_t bullets;
    notification_list_t notifications;
    path_node_t points[MAX_POINTS];
    int points_count;
    bool clicked;
    sfClock *bullets_clock;
} game_data_t;

void display_game_over(game_data_t *game);

// Init
int print_game_help(void);
int init_game(game_data_t *game);
int init_assets(game_data_t *game);
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
sfText *set_text(game_data_t *game, char *txt, int size, sfVector2f pos);
sfText *set_text_const(game_data_t *game, const char *txt,
    int size, sfVector2f pos);
void start_music(game_assets_t *assets, music_id_t id);
void basic_design(game_data_t *game);
void display_overlay(game_data_t *game);

// Settings
void set_screen_text(game_data_t *game);
void set_fps_text(game_data_t *game);
void load_arrow(game_data_t *game);
void set_screen_size(game_data_t *game);
void set_reso_text(game_data_t *game);
void set_reso(game_data_t *game);
void set_utils_text(game_data_t *game);
void arrow_l_fps(game_data_t *game);
void draw_everything_sound(game_data_t *game);
void draw_bg_rectangle(game_data_t *game);
void handle_click_sound(game_data_t *game, sfVector2f click_pos);
void handle_events_sound(game_data_t *game);
void modify_sound(game_data_t *game);
void draw_reso_rectangle(game_data_t *game);
void modify_screen(game_data_t *game);
void draw_tools(game_data_t *game, sfRectangleShape *rect, int i);
void draw_everything_control(game_data_t *game);
void draw_tools_control(game_data_t *game, sfRectangleShape *rect, int i);
char *key_to_string(sfKeyCode key);
void update_music_volumes(game_data_t *game);

// Inventory
void basic_inventory(game_data_t *game);
void handle_items_hover_label(game_data_t *game, sfRectangleShape **grid);
int remove_item_from_inventory_by_name(game_data_t *game, char *item_name);
int get_item_quantity(game_data_t *game, char *item_name);
char *get_equiped_weapon(game_data_t *game);
void insert_item_at_specific_slot(game_data_t *game, char *item_name, int qty,
    int slot_id);

// Skill Tree
void display_skill_tree(game_data_t *game);
void display_icons(game_data_t *game);
void handle_click_tree(game_data_t *game, sfRectangleShape **grid);
void add_xp(game_data_t *game, int xp);
void draw_lines(game_data_t *game, sfRectangleShape ***lines);
void draw_squares(game_data_t *game, sfRectangleShape ***grid);
float get_multiplier(int lvl);

// Items utils
void display_first_book(game_data_t *game);
void display_second_book(game_data_t *game);
void display_third_book(game_data_t *game);
void first_book_callback(game_data_t *game);
void second_book_callback(game_data_t *game);
void third_book_callback(game_data_t *game);

int asprintf(char **strp, const char *fmt, ...);
char *key_to_string(sfKeyCode key);

void window_resize_handler(game_data_t *game, sfSizeEvent *evt);

// Saves
int init_game(game_data_t *game);
unsigned long get_hash_values_from_file(FILE *file);
void read_inventory(game_data_t *game, FILE *file);
int load_game(game_data_t *game);
void load_settings(game_data_t *game);
unsigned long hash_values(unsigned long base_val);
void save_global_settings(game_data_t *game);

#endif /* MY_GAME_H */
