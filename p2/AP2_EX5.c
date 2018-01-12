#include<stdio.h>
#include<math.h>

int main(void) {
    float index;

    printf("Enter the pollution index ");
    scanf("%f", &index);

    if (index < 0.05)
        printf("\nBelow normal");
    else if (index < 0.25)
        printf("\nNormal");
    else if (index < 0.30)
        printf("\nAlert!");
    else if (index < 0.40)
        printf("\nFactories from list A: SUSPENDED."); 
    else if (index < 0.50) {
        printf("\nFactories from list A: SUSPENDED."); 
        printf("\nFactories from list B: SUSPENDED."); 
    } else {
        printf("\nFactories from list A: SUSPENDED."); 
        printf("\nFactories from list B: SUSPENDED."); 
        printf("\nFactories from list C: SUSPENDED."); 
    }
        

    return 0;
}
