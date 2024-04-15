/*
** EPITECH PROJECT, 2024
** list.h
** File description:
** dd
*/

#ifndef LIST_H
    #define LIST_H

    #include "animation.h"
    #include "game_utils.h"

typedef struct plane_s {
    sprite_id_t sprite_id;
    movement_t move;
    animated_sprite_t a_sprite;
    float health;
    int points;
    float scale;
    int radius;
    int width;
    int height;
    float lifetime;
    float angle;
    sfRectangleShape *hitbox;
    sfRectangleShape *hitbox_2;
    sfCircleShape *circle;
    int in_tarea;
    rect_t rect;
} plane_t;

typedef struct data_s {
    int id;
    plane_t *entity;
    float x1;
    float y1;
    float y2;
    float x2;
    int delay;
    float speed;
    int radius;
    int deleted;
    int printed;
} data_t;

typedef struct element_s {
    data_t data;
    struct element_s *next;
    struct element_s *prev;
} element_t;

typedef struct list_s {
    int length;
    int next_id;
    element_t start;
    element_t end;
} list_t;

// LIST
void list_init(list_t *list);
void free_list(list_t *list);
element_t *add_element(list_t *list, const data_t *data);
int del_element(list_t *list, int id);
int remove_element(list_t *list, element_t *e);

#endif /* LIST_H */
