#include<stdio.h>

float power(int x, int y) {
    int num;
    float result = 1.0;
    if (y >= 0) 
        for (num = 1; num <= y; ++num, result *= x);
    else
        for (num = 1; num <= -y; ++num, result /= x);
    return result;
}

int main(void) {
    int indx, x, y;
    for (indx = 0; indx < 4; ++indx) {
        printf("Give values for x and y to calculate x ** y (x and y must be positive numbers) ");
        scanf("%d%d", &x, &y);
        printf("The result of %d ** %d = %g\n\n", x, y, power(x, y));
    }
    return 0;
}
