#ifndef MALLOC_H_
# define MALLOC_H_

#include <unistd.h>
#include <string.h>
#include <stdio.h>

struct block{
  size_t size; // taille du bloque que je soujai
  char free; //flag pour savoir si le block est free, 1->free , 0 -->not free 
  struct block *next;
};

#endif
