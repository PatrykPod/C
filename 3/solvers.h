
/*
 * File solvers.h
 * 
 * This file contains declarations for the functions in solvers.c.
 * 
 * Author: Jelte Fennema
 * Studentnumber: 10183159
 * Date: 25-02-2012
 *
 */

#ifndef SOLVERS_H
#define SOLVERS_H
#include <time.h>
#define SEED (unsigned) time(NULL)

int random_solver(maze_t*, walker_t*, int);
int left_wall_solver(maze_t*, walker_t*, int);
int right_wall_solver(maze_t*, walker_t*, int);
int smart_random_solver_1(maze_t*, walker_t*, int);
#endif
