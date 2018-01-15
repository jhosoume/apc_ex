#include<stdio.h>

int main(void) {
    int num, multiplier;
    for (num = 10; num < 21; ++num) {
        for (multiplier = 1; multiplier < 11; ++multiplier) {
            printf("%d x %2d = %3d | ", num, multiplier, num * multiplier);
        }
        printf("\n");
    } 
    return 0;
}
