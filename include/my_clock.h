/*
** EPITECH PROJECT, 2024
** my_clock.h
** File description:
** dd
*/

#ifndef MY_CLOCK_H
    #define MY_CLOCK_H

typedef struct my_clock_s {
    float elapsed;
    int running;
} my_clock_t;

void clock_init(my_clock_t *my_clock);
void clock_update(my_clock_t *my_clock, float elapsed);

#endif /* ANIMATION_H */
