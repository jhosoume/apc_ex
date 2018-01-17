#include<stdio.h>

int main(void) {
    int prev = 0, num, sum = 0;
    printf("Enter the sequence of numbers ");
    do {
        scanf("%d", &num);
        if (prev + num > sum)
            sum = prev + num;
        prev = num;
    } while(num != 0);
    printf("The biggest sum is %d.", sum);
    return 0;
}
