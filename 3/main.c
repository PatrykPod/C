/*
 * File main.c
 * 
 * This file contains the main function, it handles input
 * and calls the other functions.
 * 
 * Author: Jelte Fennema
 * Studentnumber: 10183159
 * Date: 25-02-2012
 *
 */

#include "maze.h"
#include "walker.h"
#include "solvers.h"

#define AMNT_SOLVERS 4
#define MAX_STEPS 2147483647
 
/*
 * In this function the input gets checked and the other functions are called
 * in the correct order.
 */
int main (int argc, char **argv) {
    maze_t* maze;
    char *solver[] = {"random solver", "smart random solver", "left wall solver",
        "right wall solver"};
    walker_t* walker;
    int i, count, dir, printmaze;
    if (argc < 2){
        printf("The filename of the maze should be passed as an argument\n");
        return 0;
    }

    if (argc > 2){
        i = atoi(argv[2]);
        if (i < 0){
            printf("Don't use negative numbers");
            return 0;
        }
    }
    else
        i = 0;

    if (argc > 3){
        printmaze = atoi(argv[3]);
    }
    else
        printmaze = 1;
    
    for(; i < AMNT_SOLVERS; i++){
        srand(SEED);
        dir = NORTH;
        maze = read_maze(argv[1]);
        walker = init_walker(maze);
        count = 0;
        while (count < MAX_STEPS) {
            count++;
            switch(i){
                case 0:
                    dir = random_solver(maze, walker, dir);break;
                case 1:
                    dir = smart_random_solver_1(maze, walker, dir);break;
                case 2:
                    dir = left_wall_solver(maze, walker, dir);break;
                case 3:
                    dir = right_wall_solver(maze, walker, dir);break;
            }
            if(printmaze){
                print_maze(maze, walker->row, walker->col);
                printf("%d\n", count);
            }
            
            if (at_exit(maze, walker))
                break;
        }
        if (count < MAX_STEPS)
            printf("Found exit using the %s after %d steps\n", solver[i], count);
        printf("Press key to continue\n");
        getchar();
    }

    return 0;

}
