#include <stdio.h>

int main() {
    int matrix[2][2];
    matrix [0][0] = 1;
    matrix [0][1] = 2;
    matrix [1][0] = 3;
    matrix [1][1] = 4;

    printf("Value at %d|%d is %d", 0, 0, matrix[0][0]);
    printf("Value at %d|%d is %d", 0, 1, matrix[1]);
    printf("Value at %d|%d is %d", 1, 0, matrix[2]);
    printf("Value at %d|%d is %d", 1, 1, matrix[3]);
}
