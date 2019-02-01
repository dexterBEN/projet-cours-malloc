/*
*  rey_s    
*  benoni_d
*
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//structure d'un block alloué/non-alloué
struct block{
  size_t size; // taille du bloque que je soujai
  char free; //flag pour savoir si le block est free, 1->free , 0 -->not free 
  struct block *next;
};

/*void* my_malloc(size_t size) {
  void *p = sbrk(0);
  void *request = sbrk(size);

  if(request == (void*)-1) {
    return NULL;// cas ou sbrk failed
  } else {
    
    printf("Voici le retour de malloc: %p\n", p);
    return p;
  }
}*/

static unsigned char our_memory[1024*1024];
static size_t next_index = 0;

/*void *my_malloc(size_t sz)
{
  void *memory;

  if(sizeof (our_memory) - next_index < sz){
    return NULL;
  }else{
    memory = &our_memory[next_index];
    next_index += sz;
    
    printf("Voici le retour de malloc: %p\n", memory);
    return memory;
  }

}*/

int main() 
{
  void* new_brk = sbrk(0);// retourne un pointeur contenant l'adresse du début de la heap
  printf("La heap commence à l'adresse: %p\n", new_brk);

  printf("Voicic la taille d'un int: %i \n", sizeof(int));
  //my_malloc(100);
  //printf("heloo \n");
  return EXIT_SUCCESS;
}
