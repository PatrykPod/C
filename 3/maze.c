#include "maze.h"

/* 
 * This function takes the size of the maze and allocates memory for it
 * and returns a pointer to that maze.
 */
maze_t* init_maze(int rows, int cols) {
    int i = 0;
    maze_t *maze = malloc(sizeof(maze_t));
    maze->rows = rows;
    maze->cols = cols;
    maze->maze = malloc(rows * sizeof(char*));
    for (; i < rows; i++)
        *(maze->maze + i) = malloc(cols * sizeof(char));
    return maze;
}

/*
 * This function opens a maze file and fills a maze_t struct according
 * to its contents.
 */
maze_t* read_maze(char *filename) {
    maze_t *maze;
    FILE *file;
    int rows, cols, row = 0, col = 0;
    char c;
    if ((file = fopen(filename, "r")) == NULL){
        perror("fopen");
        exit(0);
    }
    fscanf(file, "%d,%d\n", &rows, &cols);
    maze = init_maze(rows, cols);
    while ((c = getc(file)) != EOF){
        if (c == '\n'){
            row++;
            col = 0;
            printf("\n");
            continue;
        }
        printf("%c", c);
        *(*((maze->maze)+row)+col) = c;
        col++;
    }
        
    return maze;
}

/*
 * This function prints a maze with an X at the position of the walker.
 */
void print_maze(maze_t *maze, int row, int col) {
    int i = 0, j;
    for(; i < maze->rows; i++){
        for(j = 0; j < maze->cols; j++){
            if(i == row && j == col)
                printf("X");
            else
                printf("%c", *(*(maze->maze + i) + j));
        }
        printf("\n");
    }
}

/*
 * This function frees the memory of a maze.
 */
void cleanup_maze (maze_t *maze) {
    int i = 0;
    for (; i < maze->rows; i++)
        free(*(maze->maze + i));
    free(maze->maze);
    free(maze);
}
