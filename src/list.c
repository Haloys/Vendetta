/*
** EPITECH PROJECT, 2024
** list
** File description:
** list manager
*/

#include "list.h"
#include <stdlib.h>

void list_init(list_t *list)
{
    list->length = 0;
    list->next_id = 0;
    list->start.next = &list->end;
    list->end.prev = &list->start;
}

element_t *add_element(list_t *list, const data_t *data)
{
    element_t *e = malloc(sizeof(element_t));

    *e = (element_t){
        .data = (*data),
        .next = &list->end,
        .prev = list->end.prev
    };
    list->end.prev->next = e;
    list->end.prev = e;
    ++list->length;
    ++list->next_id;
    return e;
}

int del_element(list_t *list, int id)
{
    element_t *e = list->start.next;

    for (int i = 0; i < list->length; ++i) {
        if (e->data.id == id) {
            return remove_element(list, e);
        }
        e = e->next;
    }
    return RET_FAIL;
}

int remove_element(list_t *list, element_t *e)
{
    e->prev->next = e->next;
    e->next->prev = e->prev;
    list->length--;
    free(e);
    return RET_NONE;
}

void free_list(list_t *list)
{
    element_t *e = list->start.next;
    int list_len = list->length;

    for (int i = 0; i < list_len; ++i) {
        e = e->next;
        free(e->prev);
    }
}
