
/*
 * File solvers.c
 * 
 * This file contains the functions that position the walker.
 * 
 * Author: Jelte Fennema
 * Studentnumber: 10183159
 * Date: 25-02-2012
 *
 */

#include "maze.h"
#include "walker.h"

/*
 * This function checks if the given walker can move in the given direction
 * in the given maze.
 */
int check_move(maze_t *maze, walker_t *walker, int dir) {
    int xdiff = 0, ydiff = 0;
    if (dir == NORTH)
        ydiff = -1;
    else if (dir == EAST)
        xdiff = 1;
    else if (dir == SOUTH)
        ydiff = 1;
    else
        xdiff = -1;
    if (*(*(maze->maze + walker->row + ydiff) + walker->col + xdiff) == WALL)
        return 0;
    return 1;
}

/*
 * Checks if the walker is at the exit of the maze and if this is the case
 * it frees the memory of the maze and the walker.
 */
int at_exit(maze_t *maze, walker_t *walker) {
    if(*(*(maze->maze + walker->row)+walker->col) == EXIT){
        cleanup_walker(walker);
        cleanup_maze(maze);
        return 1;
    }
    return 0;
}

/*
 * This function allocates the memory of for a walker and puts it at the 
 * starting position of the maze.
 */
walker_t* init_walker(maze_t *maze) {
    walker_t *walker = malloc(sizeof(walker_t));
    int i = 0, j;
    for(; i < maze->rows; i++){
        for(j = 0; j < maze->cols; j++){
            if(*(*(maze->maze+i)+j) == START){
                walker->row = i;
                walker->col = j;
                return walker;
            }
        }
    }
    return walker;
}

/*
 * This function moves the walker if the move is valid.
 */
int move_walker(maze_t *maze, walker_t *walker, int dir) {
    if (!check_move(maze, walker, dir))
        return 0;

    if (dir == NORTH)
        walker->row--;
    else if (dir == EAST)
        walker->col++;
    else if (dir == SOUTH)
        walker->row++;
    else
        walker->col--;
    
    return 1;
}

/*
 * This function frees the memory of the walker.
 */
void cleanup_walker(walker_t *walker) {
    free(walker);
}
