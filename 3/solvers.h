#ifndef SOLVERS_H
#define SOLVERS_H
#include <time.h>
#define SEED (unsigned) time(NULL)
/* solver function that will return a direction for the next step. */
int random_solver(maze_t*, walker_t*, int);
int left_wall_solver(maze_t*, walker_t*, int);
int right_wall_solver(maze_t*, walker_t*, int);
int smart_random_solver_1(maze_t*, walker_t*, int);
#endif
