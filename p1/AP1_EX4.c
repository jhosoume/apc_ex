#include<stdio.h>
#include<math.h>

int main(void) {
    float a, b, c, delt_root;

    printf("Enter the coeficients. a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    printf("c = ");
    scanf("%f", &c);

    delt_root = sqrt((b * b) - ( 4 * a * c));
    
    printf("\nThe first root is %2.2f, the other root is %2.2f", 
            ((-b + delt_root) / (2 * a)), ((-b - delt_root) / (2 * a)));     

    return 0;
}
