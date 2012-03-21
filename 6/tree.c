#include <stdio.h>
#include <stdlib.h>

#include "maze.h"
#include "tree.h"

tree_t* init_t(maze_t *m){
    tree_t *t = malloc(sizeof(tree_t));
    t->root = malloc(sizeof(node_t));
    t->nodes = malloc(sizeof(node_t**) * m->nrows);
    for(int i = 0; i < m->nrows; i++){
        t->nodes[i] = calloc(m->ncols, sizeof(node_t*));
    }
    for (int x = 0; x < m->ncols; x++){
        for (int y = 0; y < m->nrows; y++){
            if (m->map[x][y] == START){
                t->root->x = x;
                t->root->y = y;
                t->root->weight = 1;
                t->nodes[x][y] = t->root;
                return t;
            }
        }
    }
    return NULL;
}

tree_t* create_spanning_tree(maze_t *m){
    tree_t *t = init_t(m);
    if(t == NULL){
        printf("There was no starting position found");
        return NULL;
    }
    recursive_tree(m, t->root, t);
    return t;
}

void recursive_tree(maze_t *m, node_t *n, tree_t* t){
    if (m->map[n->x][n->y] == EXIT){
        return;
    }
    check_new_node(m, n, t, 0, 1);
    check_new_node(m, n, t, 0, -1);
    check_new_node(m, n, t, 1, 0);
    check_new_node(m, n, t, -1, 0);
}

void check_new_node(maze_t *m, node_t *n, tree_t* t, int x_offset, int y_offset){
    int x_new = n->x + x_offset, 
        y_new = n->y + y_offset,
        weight_new = n->weight + 1;
    if (m->map[x_new][y_new] != WALL){
        if (t->nodes[x_new][y_new] == 0){
            t->nodes[x_new][y_new] = create_new_node(x_new, y_new, weight_new);
            recursive_tree(m, t->nodes[x_new][y_new], t);
        }
        else if (t->nodes[x_new][y_new]->weight > weight_new){
            t->nodes[x_new][y_new]->weight = weight_new;
            recursive_tree(m, t->nodes[x_new][y_new], t);
        }
    }
}
/*
void print_tree(tree_t *t, char *filename){
    
}
*/
node_t* create_new_node(int x, int y, int weight){
    node_t *n = malloc(sizeof(node_t));
    n->x = x;
    n->y = y;
    n->weight = weight;
    return n;
}

node_t* find_exit(tree_t *t, maze_t *m){
    for (int x = 0; x < m->ncols; x++){
        for (int y = 0; y < m->nrows; y++){
            if (m->map[x][y] == EXIT){
                return t->nodes[x][y];
            }
        }
    }
    return 0;
}

int mark_shortest_path(tree_t *t, maze_t *m){
    node_t *last = find_exit(t, m);
    if (last == 0){
        printf("No way to the exit has been found");
        return 0;
    }
    while (last->weight != 2){
        last = find_previous_node(t, last);
        m->map[last->x][last->y] = PATH;
    }
    return 1;
}

node_t* find_previous_node(tree_t *t, node_t *n){
    if (check_previous_node(t, n, 1, 0)) return t->nodes[n->x + 1][n->y];
    if (check_previous_node(t, n, -1, 0)) return t->nodes[n->x -1][n->y];
    if (check_previous_node(t, n, 0, 1)) return t->nodes[n->x][n->y + 1];
    if (check_previous_node(t, n, 0, -1)) return t->nodes[n->x][n->y -1];
    return 0;
}


int check_previous_node(tree_t *t, node_t *n, int x_offset, int y_offset){
    int x_new = n->x + x_offset, y_new = n->y + y_offset;
    if (t->nodes[x_new][y_new] != 0 && t->nodes[x_new][y_new]->weight == n->weight - 1){
        return 1;
    }
    return 0;
}

void cleanup_tree(tree_t *t, maze_t *m){
    for (int x = 0; x < m->nrows; x++){
        for (int y = 0; y < m->ncols; y++){
            if(t->nodes[x][y] != 0){
                free(t->nodes[x][y]);
            }
        }
        free(t->nodes[x]);
    }
    free(t); 
}
