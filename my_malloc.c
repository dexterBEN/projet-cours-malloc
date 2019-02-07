/*
** ETNA PROJECT, 09/01/2019 by rey_s, benoni_d
** Malloc
** File description:
**      This project consists in rewriting the malloc and free functions.
*/

#include "my_malloc.h"

/*
** void *p = sbrk(0): The beginning of the heap address
** void *request = sbrk(size): Changes the heap size to allocate sufficient space to the user
** return NULL: case sbrk failed
*/

void  *malloc(size_t size)
{
  void  *addr;// 
  static int i = 0;

  //Dans le cas ou la taille rentrée vaut 0 on sort de l'éxécution
  if(size == 0)
  {
    return (NULL);
  }

  size = (size - 1) / 4 * 4 + 4; //Alignement des pointer des block mémoires 
  addr = find_block(size);

  if(addr != NULL)
  {
    re_init_list();
    return (addr);
  }

  //on agrandit la taille de la heap si jamais on ne trouve pas de block de taille suffisante
  addr = sbrk(size); 

  if (addr == (void *)-1)
  {
    printf("Error : sbrk() failed\n");
    return (NULL);
  }

  if(i == 0)
  {
    g_list = NULL;
  }

  put_in_list(&g_list, size, addr);
  ++i;

  return (addr);
}

void  *find_block(size_t size)
{
  if(g_list == NULL)
  {
    return (NULL);
  }

  if(g_list->is_used == UNUSED && size <= g_list->size)
  {
    g_list->is_used = USED;
    return (g_list->addr);
  }

  while(g_list->head != 1)
  {
    if (g_list->is_used == UNUSED && size <= g_list->size)
    {
      g_list->is_used = USED;
      return (g_list->addr);
    }
    g_list = g_list->next;
  }

  re_init_list();
  return (NULL);
}
