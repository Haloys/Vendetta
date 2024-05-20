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
    #include "save.h"
    #include "map.h"
    #include "list.h"
    #include "skill_tree.h"
    #include "minigame.h"
    #include "game_keys.h"

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
} player_data_t;

typedef struct {
    float min;
    float max;
} min_max_t;

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
    bool is_fullscreen;
    bool hover_save_button;
    bool hover_array[4];
    bool hover_slot_array[3];
    bool is_navbar_visible;
    int validation_count;
    bool is_sprite_displayed;
    sfVector2f mouse_pos;
    player_data_t *player;
    int sg_x;
    int sm_x;
    int sa_x;
    int clicked_rect_index;
    int clicked_rect;
    int clicked_control;
    sfImage *cols_map;
    int key_state;
    int key_change;
    int key_update;
    sfView *game_view;
    sfView *menu_view;
    sfVector2f view_pos;
    float view_zoom;
    float target_zoom;
    map_config_t map;
    list_t enemies;
    list_t npcs;
    sfClock *animation_clock;
    sequence_click_t sequence;
    sf_to_keybind_t keybinds[KEYBINDS_COUNT];
    state_t last_state;
} game_data_t;

void npc_dialogues(game_data_t *game);

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

// Inventory
void basic_inventory(game_data_t *game);
void handle_items_hover_label(game_data_t *game, sfRectangleShape **grid);

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
#endif /* MY_GAME_H */
