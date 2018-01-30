#include <stdio.h>

void readSize(int *num_lines, int *num_columns) {
    printf("Give the number of lines of the matrix ");
    scanf("%d", num_lines);
    printf("Give the number of columns of the matrix ");
    scanf("%d", num_columns);
}

void readMatrix(int num_lines, int num_columns, float matrix[num_lines][num_columns]) {
    int line, column;
    for (line = 0; line < num_lines; ++line) {    
        for (column = 0; column < num_columns; ++column) {
            printf("[LINE] %d [COLUMN] %d:", line, column);
            scanf("%f",&matrix[line][column]);
        }
    }
}

int repeated(float *element, int num_lines, int num_columns, float matrix[num_lines][num_columns]) {
    int line, column, line2, column2, repeat = 0;
    for (line = 0; line < num_lines; ++line) {   
        for (column = 0; column < num_columns; ++column) {
            column2 = column;
            for (line2 = line; line2 < num_lines; ++line2) {
                for (;column2 < num_columns; ++column2) {
                    if (matrix[line][column] == matrix[line2][column2] && (line != line2 || column != column2)) {
                        *element = matrix[line][column]; 
                        ++repeat;
                    }
                }
                column2 = 0;
            }
            if (repeat > 0)
                break;
        }
        if (repeat > 0)
            break;
    }
    return repeat;
}

int main () {
    int num_lines, num_columns, repeats;
    float element;
    readSize(&num_lines, &num_columns);
    float mat[num_lines][num_columns];
    readMatrix(num_lines, num_columns, mat);
    repeats = repeated(&element, num_lines, num_columns, mat);
    if (repeats > 0)
        printf("Element %g repeats %d times in the matrix.\n", element, repeats);
    else
        printf("No element is repeated");

    return 0;
}
