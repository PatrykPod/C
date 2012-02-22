#include "maze.h"
#include "walker.h"
#include "solvers.h"

#define MAX_STEPS 1000

int main (int argc, char **argv) {
    maze_t* maze;
    walker_t* walker;
    int count, dir = NORTH;

    if (argc < 2){
        printf("The filename of the maze should be passed as an argument\n");
        return 0;
    }
    maze = read_maze(*(argv+1));
    walker = init_walker(maze);
    count = 0;
    while (count < MAX_STEPS) {
        count++;
        dir = random_solver(maze, walker, dir);
        print_maze(maze, walker);
        printf("%d\n", count);
        if (at_exit(maze, walker))
            break;
    }
    if (count < MAX_STEPS)
        printf("Found exit using random solver after %d steps\n", count);
    
    walker = init_walker(maze);
    count = 0;
    while (count < MAX_STEPS) {
        count++;
        dir = right_wall_solver(maze, walker, dir);
        print_maze(maze, walker);
        printf("%d\n", count);
        if (at_exit(maze, walker))
            break;
    }
    
    if (count < MAX_STEPS)
        printf("Found exit using right wall solver after %d steps\n", count);

    while (count < MAX_STEPS) {
        count++;
        dir = left_wall_solver(maze, walker, dir);
        print_maze(maze, walker);
        printf("%d\n", count);
        if (at_exit(maze, walker))
            break;
    }
    
    if (count < MAX_STEPS)
        printf("Found exit using right wall solver after %d steps\n", count);



    return 0;

}
