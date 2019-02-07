#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int *articles = NULL;
    int nb_article = 0;
    int i;

    printf("How many articles: ");
    scanf("%d", &nb_article);
    articles =  my_malloc(sizeof(int)*nb_article);

    if(articles == NULL) {
        exit(1);
    }
     
    for(i = 0; i < nb_article; i++) {
        printf("Item %d is in %d rayon \n", i + 1, i * 3);
        articles[i] = i * 3; 
    }
  
    for(i = 0; i < nb_article; i++) {
        printf("[%d]", articles[i]);
    }

    my_free(articles);

    return (0);
}
