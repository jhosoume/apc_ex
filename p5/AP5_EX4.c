#include<stdio.h>

int evenSum (int upper_limit) {
    int sum = 0, num; 
    for (num = upper_limit; num > 0; --num) {
        if (num % 2 == 0) 
            sum += num;
    }
    return sum;
}

int main(void) {
    int upper;

    printf("Enter the upper limit of the sum ");
    scanf("%d", &upper);
    if (upper >= 0)
        printf("The sum of all even numbers until %d = %d", upper, evenSum(upper));
    else
        printf("Number is not positive");

    return 0;
}
