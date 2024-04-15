/*
** EPITECH PROJECT, 2024
** game_utils.h
** File description:
** dd
*/

#ifndef GAME_UTILS
    #define GAME_UTILS

    #define RET_NONE 0
    #define RET_FAIL 84
    #define WINDOW_WIDTH 1920
    #define WINDOW_HEIGHT 1080
    #define WINDOW_FPS 60

typedef struct rect_s {
    int x;
    int y;
    int w;
    int h;
} rect_t;

typedef struct my_size_s {
    int w;
    int h;
} my_size_t;

typedef struct c_rect_s {
    int x;
    int y;
    int r;
} c_rect_t;

#endif /* GAME_UTILS */
