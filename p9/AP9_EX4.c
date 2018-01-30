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

void negativeLines(int num_lines, int num_columns, int matrix[num_lines][num_columns], int negatives[num_lines]) {
    int num_neg, column, line;
    for (line = 0; line < num_lines; ++line) {
        num_neg = 0;
        for (column = 0; column < num_columns; ++column) {
            if (matrix[line][column] < 0) {
                ++num_neg;
            }
        }
        negatives[line] = num_neg;
    }
}

void printNegs(int num_lines, int negative_lines[num_lines]) {
    int indx;
    for (indx = 0; indx < num_lines; ++indx) {
        printf("Line %d has %d negative numbers;\n", indx + 1, negative_lines[indx]);
    }
}

int main() {
    int n_lines = 2, n_columns = 2, negatives[n_lines];
    int mat[n_lines][n_columns];
    readMatrix(n_lines, n_columns, mat);
    negativeLines(n_lines, n_columns, mat, negatives);
    printNegs(n_lines, negatives);
    return 0;
}

