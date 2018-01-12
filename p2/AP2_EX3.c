#include<stdio.h>
#include<math.h>

int main(void) {
    float a, b, c, delt;

    printf("Enter the coeficients. a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    printf("c = ");
    scanf("%f", &c);

    delt = (b * b) - ( 4 * a * c);
    if (delt < 0.0)
        printf("Delta is less than zero");
    else {
        printf("\nThe first root is %2.2f, the other root is %2.2f", 
                ((-b + sqrt(delt)) / (2 * a)), ((-b - sqrt(delt)) / (2 * a)));     
    }
    return 0;
}
