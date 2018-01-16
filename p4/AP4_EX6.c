#include<stdio.h>

int main(void) {
    int indx, x, k, num;
    float result;
    for (indx = 0; indx < 4; ++indx) {
        printf("Give values for x and k to calculate x ** k (x and k must be positive numbers) ");
        scanf("%d%d", &x, &k);
        /* Calculate x  ** k */
        if (k >= 0) 
            for (num = 1, result = 1; num <= k; ++num, result *= x);
        else
            for (num = 1, result = 1.0; num <= -k; ++num, result /= x);
        printf("The result of %d ** %d = %g\n\n", x, k, result);
    }
    return 0;
}
