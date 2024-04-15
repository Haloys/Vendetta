/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_radar project
*/

#include "my_clock.h"

void clock_init(my_clock_t *clock)
{
    clock->running = 1;
    clock->elapsed = 0;
}

void clock_update(my_clock_t *clock, float elapsed)
{
    if (clock->running == 1)
        clock->elapsed += elapsed;
}
