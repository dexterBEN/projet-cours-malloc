/*
** ETNA PROJECT, 09/01/2019 by rey_s, benoni_d
** Malloc
** File description:
**      This project consists in rewriting the malloc and free functions.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//#include "free.c"

/*
** Structure d'un block alloué/non-alloué
** size_t size: taille du block
** char free: Flag pour savoir si le block est free, 1->free, 0->not free
*/

struct block
{
    size_t size;
    char free;
    struct block *next;
};

/*
** void *p = sbrk(0): The beginning of the heap address
** void *request = sbrk(size): Changes the heap size to allocate sufficient space to the user
** return NULL: case sbrk failed
*/

void *my_malloc(size_t size)
{
    void *p = sbrk(0);
    void *request = sbrk(size);

    if (request == (void*) -1) {
        return NULL;
    } else {
        assert(p == request);
        return p;
    }
}

int main()
{
    void* new_brk = sbrk(0);
    printf("La heap commence à l'adresse: %p\n", new_brk);

    int *valueNull = my_malloc(0);
    printf("Test value: %p \n", valueNull);
    return (0);
}