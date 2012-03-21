#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loods1.h"

loods1 *maak_loods(void){
    loods1 *loods = malloc(sizeof(loods1));
    loods->size = 0;
    loods->first = NULL;
    return loods;
}


int leeg(loods1 *loods){
    if(loods->first == NULL)
        return 1;
    return 0;
}

void opslaan(loods1 *loods, char *thee){
    element *new = malloc(sizeof(element));
    new->content = malloc(strlen(thee) * sizeof(char));
    strcpy(new->content, thee);
    new->next = loods->first;
    loods->first = new;
}

char *leveren(loods1 *loods){
    element *front;
    char *thee;
    if(leeg(loods))
        return NULL;
    front = loods->first;
    loods->first = front->next;
    thee = front->content;
    free(front);
    return thee;
}

int sloop_loods(loods1 *loods){
    while (leveren(loods) != NULL);
    free(loods);
    return 1;
}


