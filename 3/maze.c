#include "walker.h"
#include "maze.h"

/* Incomplete definitions of the maze support function . */
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
    printf("%d,%d\n", rows, cols);
    maze = init_maze(rows, cols);
    while ((c = getc(file)) != EOF){
        if (c == '\n'){
            row++;
            col = 0;
            printf("\n");
            continue;
        }
        *(*((maze->maze)+row)+col) = c;
        printf("%c", *(*(maze->maze+row)+col));
        col++;
    }
        
    return maze;
}

void print_maze(maze_t *maze, int row, int col) {
    int i = 0, j;
    for(; i < maze->rows; i++){
        for(j = 0; j < maze->cols; j++){
            if(i == row && j == col)
                printf("X");
            else
                printf("%c", *(*(maze->maze+i)+j));
        }
        printf("\n");
    }
}

void cleanup_maze (maze_t *maze) {
}
