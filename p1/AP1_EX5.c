#include<stdio.h>
#include<math.h>

int main(void) {
    float cat1, cat2;

    printf("Give values for the two triangle legs. L1 = ");
    scanf("%f", &cat1);
    printf("L2 = ");
    scanf("%f", &cat2);
    
    printf("\nThe hypothenuse is %3.2f", 
           sqrt(cat1 * cat1 + cat2 * cat2)); 

    return 0;
}
