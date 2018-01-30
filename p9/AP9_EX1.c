#include <stdio.h>

int main () {
    int line, column;
    int MAT[3][3];
    for (line = 0; line < 3; ++line) {     /* leitura da matriz */
        for (column = 0;column < 3; ++column) {
             scanf("%d",&MAT[line][column]);
        }
    }
    for (line = 0; line < 3; ++line) {    /* impressão da matriz */
        for (column = 0; column < 3; ++column) {
            printf("%d\t",MAT[line][column]);
        }
        printf("\n");
    }
    getchar();
    return 0;
}
