/*
 * File 2.c
 * 
 * This file contains the code for assignment 2. It decodes a text file that is
 * encoded using Caesar replacement. It uses the first parameter as the encoded
 * file and the second as the frequencies file.
 * 
 * Author: Jelte Fennema
 * Studentnumber: 10183159
 * Date: 17-02-2012
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>


FILE* open_file(char *filename);
int msg_size(FILE *msg_ptr);
int check_possibilities(FILE *msg_ptr, char letters[], double freqs[]);

/*
 * This is the main function. It opens and closes the files. It also prints the
 * final output. 
 */
int main(int argc, char *argv[]){
    if (argc < 3){
        printf("Not enough parameters have been passed\n");
        return(0);
    }
    
    int i, c, offset;
    char letters[26];
    double freqs[26];
    FILE *msg_ptr, *freq_ptr;
    msg_ptr = open_file(argv[1]);
    freq_ptr = open_file(argv[2]);
    for (i = 0; i<26; i++){
        fscanf(freq_ptr, "%c %lf\n", &letters[i], &freqs[i]);
    }
    fclose(freq_ptr);
    offset = check_possibilities(msg_ptr, letters, freqs);
    printf("\nThe decoded text is:\n");
    while ((c = getc(msg_ptr)) != EOF){ 
        if (isupper(c)){
            c = c-offset;
            if (c < 'A')
                c += 26;
        }
        else if (islower(c)){
            c = c-offset;
            if (c < 'a')
                c += 26;
        }
        printf("%c", c);
    }
    fclose(msg_ptr);
}

/*
 * This function opens a file and returns the pointer to the file.
 */
FILE* open_file(char *filename){
    printf("%s", filename);
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL){
        perror("fopen");
        exit(0);
    }
    return file;
}

/*
 * This function returns the amount of alphabetic characters that are in a file.
 */
int msg_size(FILE *msg_ptr){
    int msg_size = 0;
    char c;
    while ((c = getc(msg_ptr)) !=  EOF){
        if (!isalpha(c)){
            continue;
        }
        msg_size++;
    }
    rewind(msg_ptr);
    return msg_size;
}

/*
 * This function calculates the letter frequencies of the file using Caeser
 * replacement. It returns the one with the smallest absolute difference.
 */
int check_possibilities(FILE *msg_file, char letters[], double freqs[]){
    int k, h, i = 0, final = 0, length=msg_size(msg_file);
    double freq, margin, best_margin=2600;
    char c, letter, text[length];
    while ((c = getc(msg_file)) != EOF){
        if (!isalpha(c)){
            continue;
        }
        text[i] = tolower(c);
        i++;
    }
    rewind(msg_file);
    for (i = 0; i < 26; i++){
        int counts[26] = {0};
        for (k = 0; k < length; k++){
            letter = text[k]-i;
            if (letter < 'a')
                letter += 26;
            for (h = 0; h < 26; h++){
                if (letter == letters[h]){
                    counts[h]++;
                }
            }
        }
        margin = 0;
        for (k = 0; k < 26; k++){
            freq = (double)counts[k]/length*100;
            margin += fabs(freqs[k] - freq);
        }
        printf("%d", i);
        if (margin < best_margin){
            best_margin = margin;
            final = i;
            printf("*");
        }
        printf(" ");
    }
    printf("\n");
    return final;
}
