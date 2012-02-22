#include "maze.h"
#include "walker.h"
#include "solvers.h"

/* Will contain the definitions of the maze solver functions. */
int random_solver(maze_t *maze, walker_t *walker, int last_dir){
    int new_dir;
    while(!move_walker(maze, walker, new_dir)){
        srand(SEED);
        new_dir = rand()%4;
    }
    return new_dir;
}


int smart_random_solver_1(maze_t *maze, walker_t *walker, int last_dir){
    int j = 0; i = NORTH , new_dir, options[3];
    for(; i <= WEST; i++){
        if(i != (last_dir+2)%4){
             options[j] = i;
             j++;
        }
    }
    i = 3;
    for(; i > 0; i--){
        srand(SEED);
        new_dir = rand() % i;
        if(move_walker(options[new_dir]))
            return options[new_dir];
        options[new_dir]=options[i];
    }
    new_dir=(last_dir+2)%4;
    move_walker(new_dir);
    return new_dir;
}

int right_wall_solver(maze_t *maze, walker_t *walker, int last_dir){
    int new_dir = (last_dir+1)%4;
    while(!move_walker(maze, walker, new_dir))
        new_dir = (new_dir-1)%4;
    return new_dir;
}

int left_wall_solver(maze_t *maze, walker_t *walker, int last_dir){
    int new_dir = (last_dir-1)%4;
    while(!move_walker(maze, walker, new_dir))
        new_dir = (new_dir+1)%4;
    return new_dir;
}
/* Next super solver here.. */
