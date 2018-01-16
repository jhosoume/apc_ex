#include<stdio.h>

int main(void) {
    int prev = 0, next = 1, sum = 0;
    printf("Enter the sequence of numbers ");
    scanf("%d", &prev);
    scanf("%d", &next);
    sum = prev + next;
    while(next != 0) {
        prev = next;
        scanf("%d", &next);
        if (prev + next > sum)
            sum = prev + next;
    }
    printf("The biggest sum is %d.", sum);
    return 0;
}
