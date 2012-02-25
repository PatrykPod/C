
/*
 * File walker.h
 * 
 * This file contains declarations for the functions in walker.c
 * and it declares the the defines the walker_t struct.
 * 
 * Author: Jelte Fennema
 * Studentnumber: 10183159
 * Date: 25-02-2012
 *
 */

#ifndef WALKER_H
#define WALKER_H

typedef struct {
    int row, col;    
} walker_t;


walker_t* init_walker(maze_t*);
int move_walker(maze_t*, walker_t*, int);
int at_exit(maze_t*, walker_t*);
int check_move(maze_t*, walker_t*, int);
void cleanup_walker(walker_t*);

#endif
