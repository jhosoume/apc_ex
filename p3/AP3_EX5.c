#include<stdio.h>

int main(void) {
    int num, code, max_code = 1, min_code = 1;
    float height, max_height = 0.0, min_height = 99999999.99;
    printf("Enter the code and height of 10 athletes ");
    for (num = 1; num < 11; ++num) {
        scanf("%d%f", &code, &height);
        if (height > max_height) {
            max_code = code;
            max_height = height;
        }
        if (height < min_height) {
            min_code = code;
            min_height = height;
        }
    } 
    printf("\nThe athlete %d is the tallest with %2.2f.", max_code, max_height);
    printf("\nThe athlete %d is the shortest with %2.2f.", min_code, min_height);
    return 0;
}
