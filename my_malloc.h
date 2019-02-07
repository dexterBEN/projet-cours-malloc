/*
** ETNA PROJECT, 07/02/2019 by rey_s, benoni_d
** Malloc
** File description:
**      [...]
*/

#ifndef _MY_MALLOC_H_
# define _MY_MALLOC_H_

#include <unistd.h>
#include <string.h>
#include <stdio.h>

struct block {
    size_t size;
    char free;
    struct block *next;
};

void *malloc(size_t size);
void free(void *ptr);

#endif
