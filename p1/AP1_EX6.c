#include<stdio.h>

int main(void) {
    float g1, g2, g3;
    float w1, w2, w3;

    printf("Enter three students grades ");
    scanf("%f%f%f", &g1, &g2, &g3);
    printf("Now, enter the weights for each grade ");
    scanf("%f%f%f", &w1, &w2, &w3);
    
    printf("\nThe final mean is %3.2f", 
           (w1 * g1 + w2 * g2 + w3 * g3)/(w1 + w2 + w3)); 

    return 0;
}
