#include <stdio.h>

void readBombs(int num_lines, int num_columns, char bombs[num_lines][num_columns]) {
    int line, column;
    printf("Enter values of the matrix\n");
    for (line = 0; line < num_lines; ++line) {    
        for (column = 0; column < num_columns; ++column) {
            do {
                printf("[LINE] %d [COLUMN] %d :", line, column);
                scanf(" %c", &bombs[line][column]);
            } while(bombs[line][column] != '*' && bombs[line][column] != '-');
        }
    }
}

int neighborBombs(int current_line, int current_column, int num_lines, int num_columns, char bombs[num_lines][num_columns]) {
    int total = 0, line, column;
    printf("Current line %d\n", current_line);
    printf("Current column %d\n", current_column);
    for (line = current_line - 1; line <= current_line + 1; ++line) {
        for (column = current_column - 1; column <= current_column + 1; ++column) {
            if (line >= 0 && column >= 0 && line < num_lines && column < num_columns && (line != current_line || column != current_column)) {
                printf("Checking %d and %d\n", line, column);
                if (bombs[line][column] == '*') {
                    ++total;
                }
            }
        }
    }
    return total;
}

void getBombs(int num_lines, int num_columns, int num_bombs[num_lines][num_columns], char bombs[num_lines][num_columns]) {
    int line, column;
    for (line = 0; line < num_lines; ++line) {
        for (column = 0; column < num_columns; ++column) {
            num_bombs[line][column] = neighborBombs(line, column, num_lines, num_columns, bombs); 
        }
    }
}

void printNBombs(int num_lines, int num_columns, int num_bombs[num_lines][num_columns]) {
    int line, column;
    for (line = 0; line < num_lines; ++line) {
        for (column = 0; column < num_columns; ++column) {
            printf("%d ", num_bombs[line][column]);
        }
        printf("\n");
    }
}

int main() {
    int n_lines = 5, n_columns = 5;
    char bombs[n_lines][n_columns];
    int n_bombs[n_lines][n_columns];
    readBombs(n_lines, n_columns, bombs);
    getBombs(n_lines, n_columns, n_bombs, bombs);
    printNBombs(n_lines, n_columns, n_bombs);
    return 0;
}

