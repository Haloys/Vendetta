/*
** EPITECH PROJECT, 2024
** B-CPE-200-PAR-2-1-corewar-flavien.de-rigne
** File description:
** List system
*/

#include <stdlib.h>

#include "list.h"
#include "my_game.h"

void list_init(list_t *list, void (*free_data)(void *))
{
    list->length = 0;
    list->next_id = 0;
    list->start.next = &list->end;
    list->end.prev = &list->start;
    list->free_data = free_data;
}

element_t *list_add_element(list_t *list, void *data)
{
    element_t *e = malloc(sizeof(element_t));

    if (e == NULL) {
        return NULL;
    }
    *e = (element_t){
        .data = data,
        .id = list->next_id,
        .next = &list->end,
        .prev = list->end.prev
    };
    list->end.prev->next = e;
    list->end.prev = e;
    ++list->length;
    ++list->next_id;
    return e;
}

int list_remove_element(list_t *list, element_t *e)
{
    e->prev->next = e->next;
    e->next->prev = e->prev;
    list->length--;
    list->free_data(e->data);
    free(e);
    return RET_NONE;
}

void free_list(list_t *list)
{
    element_t *e = list->start.next;
    int list_len = list->length;

    for (int i = 0; i < list_len; ++i) {
        e = e->next;
        list_remove_element(list, e->prev);
    }
    list->length = 0;
    list->next_id = 0;
}
