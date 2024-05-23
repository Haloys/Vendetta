/*
** EPITECH PROJECT, 2024
** Vendetta / Header
** File description:
** Inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_
    #include <stdlib.h>
    #include <stdbool.h>
    #include <SFML/Graphics.h>

    #define WIDTH 5
    #define HEIGHT 5
    #define COUNT 29
    #define SIZE 110
    #define GAP 12
    #define SQUARE_BG sfColor_fromRGBA(255, 255, 255, 50)
    #define BORDER sfColor_fromRGBA(255, 255, 255, 125)
    #define BORDER_HOVER sfColor_fromRGB(51, 217, 122)
    #define RED_BTN_BG sfColor_fromRGBA(242, 115, 132, 51)
    #define RED_BTN_OUTLINE sfColor_fromRGBA(242, 115, 132, 128)
    #define RED_HOVER sfColor_fromRGB(242, 115, 132)

    #define GET_SENTENCE(x) (x ? "YES" : "NO")

    #define INVENTORY_SLOT_COUNT_ALL 31

typedef struct game_data_s game_data_t;

typedef enum item_type_s {
    ITEM_MISC,
    ITEM_WEAPON,
    ITEM_ARMOR,
    ITEM_HELMET,
    ITEM_SHOES,
} item_type_t;

typedef struct item_s {
    char *name;
    char *label;
    int sprite_id;
    float rarity;
    float weight;
    bool is_stackable;
    bool is_equipable;
    bool is_usable;
    item_type_t type;
    int damage;
    int armor;
    int health;
    int speed;
    void (*effect)(game_data_t *game);
} item_t;

typedef struct inventory_slot_s {
    item_t *item;
    int quantity;
    float weight;
    bool is_selected;
} inventory_slot_t;

typedef struct inventory_s {
    inventory_slot_t slots[29];
    float total_weight;
} inventory_t;

void handle_hover(sfRectangleShape* square, sfVector2i mouse_pos);
sfRectangleShape *create_rectangle(game_data_t *game, sfVector2f pos,
    int sizex, int sizey);
int is_valid_weight(game_data_t *game, float added_weight);
void update_inventory_weight(game_data_t *game);
item_t *get_item_by_name(char *item_name);
void display_item_images(game_data_t *game, sfRectangleShape **grid);
void handle_drag_and_drop(game_data_t *game, sfRectangleShape **grid);
void calculate_player_stats(game_data_t *game);
void swap_items(game_data_t *game, int dest, int src);
void insert_item_in_inventory(game_data_t *game, char *item_name, int qty);
void use_or_trash(game_data_t *game, int slot_id, int item_id);

#endif /* !INVENTORY_H_ */
