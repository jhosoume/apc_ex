#include<stdio.h>

#define PI 3.14

int main(void) {
    float radius, height;
    printf("Enter values of the radius and the height of the circular cilinder  ");
    scanf("%f%f", &radius, &height);
    printf("\nThe volume is %.3f", PI * radius * radius * height);
    return 0;
}
