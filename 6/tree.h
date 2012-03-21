#ifndef TREE_H
#define TREE_H

typedef struct node_t{
    int x, y, weight;
} node_t;

typedef struct tree_t {
    node_t *root, ***nodes;
} tree_t;


tree_t* create_spanning_tree(maze_t *m);
void print_tree(tree_t *t, char *filename);
void recursive_tree(maze_t*, node_t*, tree_t*);
void check_new_node(maze_t*, node_t*, tree_t*, int, int);
node_t* create_new_node(int x, int y, int weight);
node_t* find_previous_node(tree_t*, node_t*);
int check_previous_node(tree_t*, node_t*, int, int);
int mark_shortest_path(tree_t *t, maze_t *m);
void cleanup_tree(tree_t *t, maze_t*);

#endif
