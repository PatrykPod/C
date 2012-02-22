/* Contains function related to the maze map of the game. */

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

/* Incomplete type declaration. */
typedef struct {
    int rows, cols;
    char **maze;
} maze_t;


/* Incomplete declarations of the support functions. */
maze_t* init_maze(int x, int y);
maze_t* read_maze(char *mazefile);
void print_maze(maze_t*, int, int);
void cleanup_maze(maze_t*);

#endif
