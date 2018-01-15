#include<stdio.h>

int main(void) {
    int sum, num;
    for (num = 1; num < 11; ++num) {
        sum += num;
    } 
    printf("Sum of numbers 1 + 2 + ... + 10 = %d", sum);
    return 0;
}
