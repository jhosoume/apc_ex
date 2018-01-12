#include<stdio.h>

int main(void) {
    int num1, num2;

    /* Getting input */
    printf("Enter num1 = ");
    scanf("%d", &num1);
    printf("\nEnter num2 = ");
    scanf("%d", &num2);
   
    /*Writing mean*/ 
    printf("\nThe mean of the two numbers is %2.2f", (num1 + num2)/2.0 );

    return 0;
}
