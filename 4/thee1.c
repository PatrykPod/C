#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loods1.h"
#define BUFFERSIZE 200

int main(void){
    char input[BUFFERSIZE], *command, *theesoort;
    loods1 *loods = maak_loods();
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
            sloop_loods(loods);
            printf("Tot ziens\n");
            return 0;
        }
        else if (!strcmp("opslaan", command)){
            theesoort = strtok(NULL, "\0");
            if (theesoort == NULL){
                printf("Specificeer de thee bij het opslaan.");
                continue;
            }
            printf("%s wordt opgeslagen", theesoort);
            opslaan(loods, theesoort);
        }
        else if (!strcmp("leveren", command)){
            theesoort = leveren(loods);
            if (theesoort == NULL){
                printf("Er is geen thee meer in vooraad.");
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
