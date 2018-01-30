#include <stdio.h>

void readMatrix(int num_lines, int num_columns, int matrix[num_lines][num_columns]) {
    int line, column;
    printf("Enter values of the matrix\n");
    for (line = 0; line < num_lines; ++line) {    
        for (column = 0; column < num_columns; ++column) {
            printf("[LINE] %d [COLUMN] %d :", line, column);
            scanf("%d",&matrix[line][column]);
        }
    }
}

void readLine(int num_columns, int line[num_columns]) {
    int column;
    printf("Enter values of the line to be compared with ");
    for (column = 0; column < num_columns; ++column) {
        printf("[COLUMN] %d :", column);
        scanf("%d",&line[column]);
    }
}

int findLine(int num_lines, int num_columns, int matrix[num_lines][num_columns], int line_match[num_columns]) {
    int column, flag = 1, line;
    for (line = 0; line < num_lines; ++line) {
        for (column = 0; column < num_columns; ++column) {
            if (matrix[line][column] != line_match[column]) {
                flag = 0;
                break;
            }
        }
        if (flag)
            return line;
    }
    return -1;
}


int main() {
    int n_lines = 5, n_columns = 5, line;
    int line_match[n_columns];
    int mat[n_lines][n_columns];
    readMatrix(n_lines, n_columns, mat);
    readLine(n_columns, line_match);
    line = findLine(n_lines, n_columns, mat, line_match); 
    if (line == -1) 
        printf("There is no line equal to vector in matrix");
    else
        printf("V eqauls to line %d", line);
    return 0;
}

