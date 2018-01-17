#include<stdio.h>
float biggest(float num1, float num2, float num3) {
    if (num1 > num2 && num1 > num3)
        return num1;
    else if (num2 > num3)
        return num2;
    else 
        return num3;
}

int main(void) {
    float n1, n2, n3;
    printf("Enter three numbers that will be compared ");
    scanf("%f%f%f", &n1, &n2, &n3);
    printf("The biggest among the three is %g", biggest(n1, n2, n3));
    return 0;
}
