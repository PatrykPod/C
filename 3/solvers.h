#ifndef SOLVERS_H
#define SOLVERS_H
#define SEED 1
/* solver function that will return a direction for the next step. */
int random_solver(maze_t*, walker_t*, int);
int wall_solver(maze_t*, walker_t*, int);

#endif
