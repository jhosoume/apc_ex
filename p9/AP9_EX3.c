#include <stdio.h>

void readMatrix(int num_lines, int num_columns, int matrix[num_lines][num_columns]) {
    int line, column;
    for (line = 0; line < num_lines; ++line) {    
        for (column = 0; column < num_columns; ++column) {
            printf("[LINE] %d [COLUMN] %d:", line, column);
            scanf("%d",&matrix[line][column]);
        }
    }
}

int nullColumns(int num_lines, int num_columns, int matrix[num_lines][num_columns]) {
    int num_null = 0, column, flag = 1, line;
    for (column = 0; column < num_columns; ++column) {
        for (line = 0; line < num_lines; ++line) {
            if (matrix[line][column] != 0) {
                flag = 0;
                break;
            }
        }
        if (flag)
            ++num_null;
    }
    return num_null;
}

int nullLines(int num_lines, int num_columns, int matrix[num_lines][num_columns]) {
    int num_null = 0, column, flag = 1, line;
    for (line = 0; line < num_lines; ++line) {
        for (column = 0; column < num_columns; ++column) {
            if (matrix[line][column] != 0) {
                flag = 0;
                break;
            }
        }
        if (flag)
            ++num_null;
    }
    return num_null;
}

void nulls(int *num_null_lines, int *num_null_columns, int num_lines, int num_columns, int matrix[num_lines][num_columns]) {
    *num_null_lines = nullLines(num_lines, num_columns, matrix);
    *num_null_columns = nullColumns(num_lines, num_columns, matrix);
}

int main() {
    int n_lines = 4, n_columns = 4, null_lines, null_columns;
    int mat[n_lines][n_columns];
    readMatrix(n_lines, n_columns, mat);
    nulls(&null_lines, &null_columns, n_lines, n_columns, mat);
    printf("The informed matrix has %d null lines and %d null columns.\n", null_lines, null_columns);
    return 0;
}

