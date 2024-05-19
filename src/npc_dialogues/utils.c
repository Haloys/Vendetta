/*
** EPITECH PROJECT, 2024
** Vendetta
** File description:
** Utils
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#include "my_game.h"
#include "dialogues.h"

/*
This function converts a UTF-8 string to a UTF-32 string.

- Unicode Standard: https://unicode.org/
- UTF-8 conversion libraries like `utf8.h` by Jeff Bezanson:
    https://github.com/sheredom/utf8.h

Note: Make sure text files are encoded in UTF-8 !!!!!.
*/

static sfUint32 *handle_utf8_byte_2byte(const char *utf8str, size_t *i,
    size_t *j, sfUint32 *utf32str)
{
    utf32str[(*j)] = ((utf8str[*i] & 0x1F) << 6) | (utf8str[*i + 1] & 0x3F);
    (*i) += 2;
    (*j)++;
    return utf32str;
}

static sfUint32 *handle_utf8_byte_3byte(const char *utf8str, size_t *i,
    size_t *j, sfUint32 *utf32str)
{
    utf32str[(*j)] = ((utf8str[*i] & 0x0F) << 12) |
        ((utf8str[*i + 1] & 0x3F) << 6) | (utf8str[*i + 2] & 0x3F);
    (*i) += 3;
    (*j)++;
    return utf32str;
}

static sfUint32 *handle_utf8_byte_4byte(const char *utf8str, size_t *i,
    size_t *j, sfUint32 *utf32str)
{
    utf32str[(*j)] = ((utf8str[*i] & 0x07) << 18) |
        ((utf8str[*i + 1] & 0x3F) << 12) | ((utf8str[*i + 2] & 0x3F) << 6) |
        (utf8str[*i + 3] & 0x3F);
    (*i) += 4;
    (*j)++;
    return utf32str;
}

static sfUint32 *handle_utf8_byte(const char *utf8str, size_t *i,
    size_t *j, sfUint32 *utf32str)
{
    uint8_t c = utf8str[*i];

    if (c < 0x80) {
        utf32str[(*j)] = c;
        (*i)++;
        (*j)++;
        return utf32str;
    }
    if ((c & 0xE0) == 0xC0)
        return handle_utf8_byte_2byte(utf8str, i, j, utf32str);
    if ((c & 0xF0) == 0xE0)
        return handle_utf8_byte_3byte(utf8str, i, j, utf32str);
    if ((c & 0xF8) == 0xF0)
        return handle_utf8_byte_4byte(utf8str, i, j, utf32str);
    free(utf32str);
    return NULL;
}

sfUint32 *utf8_to_utf32(const char *utf8str)
{
    size_t len = strlen(utf8str);
    sfUint32 *utf32str = malloc((len + 1) * sizeof(sfUint32));
    size_t i = 0;
    size_t j = 0;

    if (!utf32str)
        return NULL;
    while (utf8str[i]) {
        utf32str = handle_utf8_byte(utf8str, &i, &j, utf32str);
        if (!utf32str)
            return NULL;
    }
    utf32str[j] = 0;
    return utf32str;
}
