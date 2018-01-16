#include<stdio.h>

int main(void) {
    int time, times, fact, num, indx;
    printf("How many times do you want to calculate a factorial (n!) ? ");
    scanf("%d", &times);
    for (time = 0; time < times; ++time) {
        printf("Enter the number n to be applied factorial ");
        scanf("%d", &num);
        fact = 1;
        for(indx = num; indx > 0; --indx)
            fact *= indx;
        printf("%d! = %d\n", num, fact);
    }
    return 0;
}
