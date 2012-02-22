#ifndef WALKER_H
#define WALKER_H
/* Incomplete type declaration. */
typedef struct {
    int row, col;    
} walker_t;


/* Incomplete declarations of the support functions. */
walker_t* init_walker(maze_t*);
int move_walker(maze_t*, walker_t*, int);
int at_exit(maze_t*, walker_t*);
int check_move(maze_t*, walker_t*, int);
void cleanup_walker(walker_t*);

#endif
