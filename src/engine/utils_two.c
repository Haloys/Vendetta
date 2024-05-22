/*
** EPITECH PROJECT, 2024
** Vendetta / Game Engine
** File description:
** Utils Two
*/

#include "my_game.h"
#include "list.h"
#include "entity.h"

void basic_design(game_data_t *game)
{
    sprite_id_t elements[] = {SP_MAIN_BG};
    size_t element_count = 1;

    for (size_t i = 0; i < element_count; i++) {
        sfRenderWindow_drawSprite(game->window,
            get_sprite(game, elements[i]), NULL);
    }
}

int list_remove_element_by_id(list_t *list, int id)
{
    element_t *current = list->start.next;

    while (current != &list->end) {
        if (current->id == id) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            list->free_data(current->data);
            free(current);
            list->length--;
            return RET_NONE;
        }
        current = current->next;
    }
    return RET_FAIL;
}

void remove_item_from_list(game_data_t *game, item_entity_t *item)
{
    element_t *current = game->entities.start.next;

    while (current != &game->entities.end) {
        if (current->data == item) {
            list_remove_element_by_id(&game->entities, current->id);
            break;
        }
        current = current->next;
    }
}
