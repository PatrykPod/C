#include "maze.h"
#include "walker.h"

/* Incomplete definitions of the walker support function . */
int check_move( ) {
    return 0;
}

int at_exit(maze_t *maze, walker_t *walker) {
    return 0;
}

walker_t* init_walker(  ) {
    walker_t *walker = malloc(sizeof(walker_t));
    return walker;
}

int move_walker(maze_t *maze, walker_t *walker, int dir) {
    return 0;
}

void cleanup_walker(walker_t *walker) {
    
}
