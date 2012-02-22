#include "maze.h"
#include "walker.h"
#include "solvers.h"

/* Will contain the definitions of the maze solver functions. */
int random_solver(maze_t *maze, walker_t *walker, int last_dir){
    int new_dir;
    while(new_dir != (last_dir + 2)%4 && !move_walker(maze, walker, new_dir)){
        srand(SEED);
        new_dir = rand()/(RAND_MAX/4);
    }
    return new_dir;
}

int wall_solver(maze_t *maze, walker_t *walker, int last_dir){
    int new_dir = (last_dir+1)%4;
    while(!move_walker(maze, walker, new_dir))
        new_dir = (new_dir-1)%4;
    return new_dir;
}
/* Next super solver here.. */
