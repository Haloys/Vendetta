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
    #include "resources.h"
    #include "list.h"
    #include "game_utils.h"
    #include <stdbool.h>

typedef enum state_e {
    LOADING_SCREEN,
    MAIN_MENU,
    SETTINGS,
    HELP,
    PLAYING,
    PAUSE,
} state_t;

typedef struct game_assets_s {
    sfTexture *texture[IMAGE_COUNT];
    sfSprite *sprite[SPRITE_COUNT];
    sfSoundBuffer *sound[SOUND_COUNT];
    sfMusic *music[MUSIC_COUNT];
} game_assets_t;

typedef struct opts_s {
    int hitboxes;
    int sprites;
    int quadtree_view;
    int paused;
} opts_t;

typedef struct corner_s {
    rect_t rect;
    sfRectangleShape *hitbox;
    element_t **planes;
    int planec;
    struct corner_s *corners[4];
} corner_t;

#define NAVBAR_TEXT_COLOR sfColor_fromRGB(197, 197, 197)
#define NAVBAR_LINE_COLOR sfColor_fromRGBA(255, 255, 255, 76)
#define ACTIVE_NAVBAR_TEXT_COLOR sfColor_fromRGB(51, 217, 122)

typedef struct navbar_element_s {
    const char *label;
    sprite_id_t icon;
    sfVector2f position;
    sfVector2f size;
} navbar_element_t;

typedef struct game_data_s {
    char name[10];
    sfVideoMode video_mode;
    sfRenderWindow *window;
    state_t state;
    sfClock *clock;
    sfCursor *cursor;
    game_assets_t assets;
    plane_t *plane;
    sfFont *font;
    list_t towers;
    list_t planes;
    float last_update;
    int score;
    int target_miss;
    int highest_score;
    int crash;
    int success;
    opts_t opts;
    sfClock *fps_clock;
    sfClock *time;
    my_clock_t delay_clock;
    corner_t corner;
    sfText *help_text;
    float speed;
    sfUint8 *pixels;
    bool hover_save_button;
    int mouse_x;
    int mouse_y;
    bool hover_array[4];
    bool hover_slot_array[3];
} game_data_t;

void draw_navbar(game_data_t *game);

int print_game_help(void);

void new_set_text(game_data_t *game, char *txt, int size, sfVector2f pos);

int init_game(game_data_t *game, char **av);
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

// Menu events
void m_mouse_button_pressed(game_data_t *game, sfMouseButtonEvent evt);
// Ingame events
void p_mouse_button_pressed(game_data_t *game, sfMouseButtonEvent evt);

void process_loop_in_game(game_data_t *game, float elapsed);

// Score manager
void start_music(game_assets_t *assets, music_id_t id);
sfText *set_text(game_data_t *game, char *txt, int size, sfVector2f pos);
void set_score(game_data_t *game, int new_points);

int parse_file(char *filepath, game_data_t *game);

plane_t *entity_create(sprite_id_t sprite_id);
void entity_init(plane_t *plane, sprite_id_t entity_type);
void entity_draw(plane_t *plane, game_data_t *game);
void entity_update(game_data_t *game, plane_t *plane, float elapsed);
int is_plane_active(data_t *data, game_data_t *game);
void entity_init_plane(data_t *d);

#endif /* MY_GAME_H */
