#include <stdio.h>
int main (void) {
    int num1, num2;
    printf("Inform first value: ");
    scanf("%d",&num1);
    printf("Inform second value: ");
    scanf("%d",&num2);
    if (num1 == num2)
        printf("\nNumbers are equals = %d", num1);
    else
        printf("\nNumbers are different, %d and %d", num1, num2);
    return(0);
}
