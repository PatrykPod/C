#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


FILE* open_file(char *filename);
int msg_size(char *msg_ptr);
int check_possibilities(char *msg_ptr, char letters[], double freqs[]);
int main(int argc, char *argv[]){
    if(argc < 3)
        printf("Not enough parameters have been passed\n");
    else{
        int i, c, offset;
        char letters[26];
        double freqs[26];
        FILE *msg_ptr, *freq_ptr;
        freq_ptr = open_file(argv[2]);
        for(i = 0; i<26; i++){
            fscanf(freq_ptr, "%c %lf\n", &letters[i], &freqs[i]);
            printf("%d: %c %lf\n", i, letters[i], freqs[i]);
        }
        offset = check_possibilities(argv[1], letters, freqs);
        msg_ptr = open_file(argv[1]);
        while((c = getc(msg_ptr)) != EOF){ 
            if(isupper(c)){
                c = c-offset;
                if(c < 'A')
                    c += 26;
            }
            else if(islower(c)){
                c = c-offset;
                if(c < 'a')
                    c += 26;
            }
            printf("%c", c);
        }
	}
}

FILE* open_file(char *filename){
    FILE *file;
    if((file = fopen(filename, "r")) == NULL){
        perror("fopen");
        exit(0);
    }
    return file;
}
int msg_size(char *msg_ptr){
    int msg_size = 0;
    char c;
    FILE *msg_file;
    msg_file = open_file(msg_ptr);
    while((c = getc(msg_file)) !=  EOF){
        if(!isalpha(c)){
            continue;
        }
        msg_size++;
    }
    return msg_size;
}
int check_possibilities(char *msg_ptr, char letters[], double freqs[]){
    int k, h, i = 0, final = 0, length=msg_size(msg_ptr);
    double freq, margin, best_margin=2600;
    char c, letter, text[length];
    FILE *msg_file;
    msg_file = open_file(msg_ptr);
    while((c = getc(msg_file)) != EOF){
        if(!isalpha(c)){
            continue;
        }
        text[i] = tolower(c);
        i++;
    }
    for(i = 0; i < 26; i++){
        printf("%d: ", i);
        int counts[26] = {0};
        for(k = 0; k < length; k++){
            letter = text[k]-i;
            if(letter < 'a')
                letter += 26;
            printf("%c", letter);
            for(h = 0; h < 26; h++){
                if(letter == letters[h]){
                    counts[h]++;
                }
            }
        }
        margin = 0;
        for(k = 0; k < 26; k++){
            freq = (double)counts[k]/length*100;
            margin += fabs(freqs[k] - freq);
        }
        if (margin < best_margin){
            best_margin = margin;
            final = i;
            printf("*");
        }
        printf("\n");
    }
    return final;
}
