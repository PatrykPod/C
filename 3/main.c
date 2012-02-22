#include "maze.h"
#include "walker.h"
#include "solvers.h"

#define AMNT_SOLVERS 4
#define MAX_STEPS 1000

int main (int argc, char **argv) {
    maze_t* maze;
    char *solver[] = {"random solver", "smart random solver", "left wall solver",
        "right wall solver"};
    walker_t* walker;
    int i = 0, count, dir = NORTH;

    if (argc < 2){
        printf("The filename of the maze should be passed as an argument\n");
        return 0;
    }
    for(; i < AMNT_SOLVERS; i++){
        srand(SEED);
        maze = read_maze(*(argv+1));
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
            print_maze(maze, walker->row, walker->col);
            printf("%d\n", count);
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
