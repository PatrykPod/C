#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loods1.h"
#define BUFFERSIZE 200


int main(void){
    char input[BUFFERSIZE], *command, *theesoort;
    loods1 *loods_1 = maak_loods();

    loods1 *loods_2 = maak_loods();
    printf("Welkom bij ons theebedrijf. Geef opdrachten:");
    while (1){
        printf("\n> ");
        if (fgets(input, sizeof input, stdin) == NULL){
            printf("Er is iets raars mis gegaan bij je input.");
            continue;
        }
        
        if (input[strlen(input) - 1] == '\n'){
            input[strlen(input) - 1] = '\0';
        }
        command = strtok(input, " \0");
        if (!strcmp("stop", command)){
            sloop_loods(loods_1);
            printf("Tot ziens\n");
            return 0;
        }
        else if (!strcmp("opslaan1", command)){
            theesoort = strtok(NULL, "\0");
            if (theesoort == NULL){
                printf("Specificeer de thee bij het opslaan.");
                continue;
            }
            printf("%s wordt opgeslagen in loods 1", theesoort);
            opslaan(loods_1, theesoort);
        }
        else if (!strcmp("verplaatsen12", command)){
            theesoort = leveren(loods_1);
            if (theesoort == NULL){
                printf("Er is geen thee meer in vooraad in loods 1.");
                continue;
            }
            opslaan(loods_2, theesoort);
            printf("%s werdt verplaatst uit loods 1 naar loods 2.", theesoort);
        }
        else if (!strcmp("leveren1", command)){
            theesoort = leveren(loods_1);
            if (theesoort == NULL){
                printf("Er is geen thee meer in vooraad in loods 1.");
                continue;
            }
            printf("%s wordt geleverd", theesoort);
        }
        else if (!strcmp("opslaan2", command)){
            theesoort = strtok(NULL, "\0");
            if (theesoort == NULL){
                printf("Specificeer de thee bij het opslaan.");
                continue;
            }
            printf("%s wordt opgeslagen in loods 2", theesoort);
            opslaan(loods_2, theesoort);
        }
        else if (!strcmp("verplaatsen21", command)){
            theesoort = leveren(loods_2);
            if (theesoort == NULL){
                printf("Er is geen thee meer in vooraad in loods 2.");
                continue;
            }
            opslaan(loods_1, theesoort);
            printf("%s werdt verplaatst uit loods 2 naar loods 1.", theesoort);
        }
        else if (!strcmp("leveren2", command)){
            theesoort = leveren(loods_2);
            if (theesoort == NULL){
                printf("Er is geen thee meer in vooraad in loods 2.");
                continue;
            }
            printf("%s wordt geleverd", theesoort);
        }
        else {
            printf("Dit is geen geldig commando.");
        }
    }
    return 0;
}
