#include<stdio.h>

int main(void) {
    float n1, n2, n3;
    printf("Enter three grades ");
    scanf("%f%f%f", &n1, &n2, &n3);
    printf("The mean is %2.2f", (n1 + 3*n2 + 4*n3)/8);
    return 0;
}
