/*
 * File solvers.c
 * 
 * This file contains the functions that describe the solving algorithms
 * the walker is using.
 * 
 * Author: Jelte Fennema
 * Studentnumber: 10183159
 * Date: 25-02-2012
 *
 */

#include "maze.h"
#include "walker.h"
#include "solvers.h"

/*
 * This solver is entirely random, all the four directions are 
 * put in an array and all of them are tried in a random way.
 */
int random_solver(maze_t *maze, walker_t *walker, int last_dir){
    int new_dir, i = NORTH, options[] = {NORTH, EAST, SOUTH, WEST};
    i = 4;
    for(; i > 1; i--){
        new_dir = rand() % i;
        if(move_walker(maze, walker, options[new_dir]))
            return options[new_dir];
        options[new_dir]=options[i-1];
    }
    move_walker(maze, walker, options[0]);
    return options[0];
}

/*
 * This solver is the same as the random solver except for one point,
 * it only goes the way it came from if it has no other choice.
 */
int smart_random_solver_1(maze_t *maze, walker_t *walker, int last_dir){
    int j = 0, i = NORTH , new_dir, options[] = {NORTH, EAST, SOUTH, WEST};
    options[(last_dir+2)%4] = WEST;
    i = 3;
    for(; i > 1; i--){
        new_dir = rand() % i;
        if(move_walker(maze, walker, options[new_dir]))
            return options[new_dir];
        options[new_dir]=options[i-1];
    }
    if(move_walker(maze, walker, options[0]))
        return options[0];
    new_dir=(last_dir+2)%4;
    move_walker(maze, walker, new_dir);
    return new_dir;
}

/*
 * This solver follows the right wall. It does this by trying to go right,
 * if that fails it tries to go forward, left and backward.
 */
int right_wall_solver(maze_t *maze, walker_t *walker, int last_dir){
    int new_dir = (last_dir+1)%4;
    while(!move_walker(maze, walker, new_dir)){
        new_dir = (new_dir-1);
        if(new_dir < 0)
            new_dir += 4;
    }
    
    return new_dir;
}
/*
 * The same as the right wall follower, just for the left wall.
 */
int left_wall_solver(maze_t *maze, walker_t *walker, int last_dir){
    int new_dir = (last_dir-1);
    if(new_dir < 0)
        new_dir += 4;
    while(!move_walker(maze, walker, new_dir))
        new_dir = (new_dir+1)%4;
    return new_dir;
}
