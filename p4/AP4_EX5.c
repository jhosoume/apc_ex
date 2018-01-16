#include<stdio.h>

int main(void) {
    int indx, x, k, num, result;
    for (indx = 0; indx < 4; ++indx) {
        do {
            printf("Give values for x and k to calculate x ** k (x and k must be positive numbers) ");
            scanf("%d%d", &x, &k);
        } while (x < 0 || k < 0);
        /* Calculate x  ** k */
        for (num = 1, result = 1; num <= k; ++num) {
            result *= x;
        }
        printf("The result of %d ** %d = %d\n\n", x, k, result);
    }
    return 0;
}
