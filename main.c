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

  /*int *articles = NULL;
  int nb_article = 0;
  int i;
  printf("How many articles: ");
  scanf("%d", &nb_article);

  articles =  my_malloc(sizeof(int)*nb_article);

  if(articles == NULL)
  {
    exit(1);
  }

  for(i = 0; i < nb_article; i++)
  {
    printf("Item %d is in %d rayon \n", i + 1, i * 3);
    articles[i] = i * 3; 
  }

  for(i = 0; i < nb_article; i++)
  {
    printf("[%d]", articles[i]);
  }*/

  //my_free(articles);
    return (EXIT_SUCCESS);
}
