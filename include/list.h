/*
** EPITECH PROJECT, 2024
** B-CPE-200-PAR-2-1-corewar-flavien.de-rigne
** File description:
** list
*/

#ifndef LIST_H_
    #define LIST_H_

    #include <stdbool.h>

typedef struct element_s {
    void *data;
    int id;
    struct element_s *next;
    struct element_s *prev;
} element_t;

typedef struct list_s {
    int length;
    int next_id;
    element_t start;
    element_t end;
    void (*free_data)(void *);
} list_t;

// LIST
void list_init(list_t *list, void (*free_data)(void *));
void free_list(list_t *list);
element_t *list_add_element(list_t *list, void *data);
int list_remove_element_if(list_t *list, int id);
int list_remove_element(list_t *list, element_t *e);

#endif /* LIST_H_ */
