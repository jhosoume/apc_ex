#include<stdio.h>

int prod(int n1, int n2) {
    int sum = 0;
    do {
        if (n1 % 2 != 0)
            sum += n2;
        n1 /= 2;
        n2 *= 2;
    } while (n1 >= 1); 
    return sum;
}

int main(void) {
    int time, n1, n2;
    printf("Enter 10 pairs of numbers to evaluate the product ");
    for (time = 0; time < 10; ++time) {
        scanf("%d%d", &n1, &n2); 
        while (n1 < 0 || n2 < 0) {
            printf("Numbers must be positive.\n");
            scanf("%d%d", &n1, &n2); 
        }
        printf("The result of %d * %d is %d\n", n1, n2, prod(n1, n2));
    }

    return 0;
}

