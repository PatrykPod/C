#include "maze.h"
#include "walker.h"

/* Incomplete definitions of the walker support function . */
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
    if (*(*(maze->maze + walker->row + xdiff) + walker->col + ydiff) == WALL)
        return 0;
    return 1;


    return 0;
}

int at_exit(maze_t *maze, walker_t *walker) {
    return 0;
}

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

int move_walker(maze_t *maze, walker_t *walker, int dir) {
    if (!check_move(maze, walker, dir))
        return 0;

    if (dir == NORTH)
        walker->col = -1;
    else if (dir == EAST)
        walker->row = 1;
    else if (dir == SOUTH)
        walker->col = 1;
    else
        walker->row = -1;
    
    return 1;
}

void cleanup_walker(walker_t *walker) {
    
}
