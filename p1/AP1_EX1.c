#include<stdio.h>

int main(void) {
    int a, b, aux;

    /* Getting input values */
    printf("Give two numbers to be swapped. A = ");
    scanf("%d", &a);
    printf(" B = ");
    scanf("%d", &b);

    /* Swapping values */
    aux = a; a = b; b = aux;
    printf("Now, A = %d, B = %d", a, b);

    return 0;
}
