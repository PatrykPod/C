
/*
 * File maze.h
 * 
 * This file contains declarations for the functions in maze.c
 * and the maze_t type declaration.
 * 
 * Author: Jelte Fennema
 * Studentnumber: 10183159
 * Date: 25-02-2012
 *
 */

#ifndef MAZE_H

#include <stdio.h>
#include <stdlib.h>
#define MAZE_H

#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3

#define WALL    '#'
#define START   'S'
#define EXIT    'E'

typedef struct {
    int rows, cols;
    char **maze;
} maze_t;


maze_t* init_maze(int x, int y);
maze_t* read_maze(char *mazefile);
void print_maze(maze_t*, int, int);
void cleanup_maze(maze_t*);

#endif
