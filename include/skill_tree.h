/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-myrpg-maxence.bunel [WSL: Ubuntu]
** File description:
** skill_tree
*/

#ifndef SKILL_TREE_H_
    #define SKILL_TREE_H_
    #include "my_game.h"

    #define RED sfColor_fromRGB(255, 111, 111)
    #define BLUE sfColor_fromRGB(109, 133, 255)
    #define YELLOW sfColor_fromRGB(240, 208, 95)
    #define GREEN sfColor_fromRGB(141, 201, 120)

typedef struct levels_s {
    int level;
    int xp_needed;
    int skill_points;
} levels_t;

static const levels_t LEVELS[] = {
    {2, 200, 1},
    {3, 400, 1},
    {4, 600, 1},
    {5, 800, 3},
    {6, 1000, 1},
    {7, 1200, 1},
    {8, 1400, 1},
    {9, 1600, 1},
    {10, 1800, 3},
    {11, 2000, 2},
    {12, 2200, 2},
    {13, 2400, 2},
    {14, 2600, 2},
    {15, 2800, 3}
};

typedef struct skill_tree_s {
    int health_lvl;
    int attack_lvl;
    int speed_lvl;
    int armor_lvl;
} skill_tree_t;

#endif /* !SKILL_TREE_H_ */
