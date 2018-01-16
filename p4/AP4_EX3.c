#include<stdio.h>

int main(void) {
    int num = 0, count, sum;
    while (1) {
        printf("Enter the upper limit of the sum ");
        scanf("%d", &num);
        if (num < 0) {
            printf("End of program");
            break;
        }
        sum = 0;
        for (count = 1; count <= num; ++count) {
           sum += count; 
        }
        printf("The sum is %d\n", sum);
    }
    return 0;
}
