
/*
 * File loods1.h
 * 
 * This file contains declarations for the functions in thee1.c
 * and the loods1 type definition.
 * 
 * Author: Jelte Fennema
 * Studentnumber: 10183159
 * Date: 25-02-2012
 *
 */
#ifndef THEE1_H
typedef struct element{
    char *content;
    struct element *next;
} element;
typedef struct {
    int size;
    element *first;
} loods1;

loods1 *maak_loods(void);
int leeg(loods1 *);
void opslaan(loods1 *, char *);
char *leveren(loods1 *);
int sloop_loods(loods1 *);

#endif
