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

/*
** Structure d'un block alloué/non-alloué
** size_t size: taille du block
** int free: Flag pour savoir si le block est free, 1->free, 0->not free
*/

struct block {
    size_t size;
    int free;
    struct block *next;
};

void *malloc(size_t size);
void free(void *ptr);

#endif
