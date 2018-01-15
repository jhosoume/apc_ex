#include<stdio.h>

int main(void) {
    int students, num, age;
    float mean;
    printf("To calculate the mean, input the size of the group ");
    scanf("%d", &students);
    printf("Now, enter the ages ");
    for (num = 0; num < students; ++num) {
        scanf("%d", &age);
        mean += age;
    } 
    printf("The mean is %2.2f.", mean/students);
    return 0;
}
