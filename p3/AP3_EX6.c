#include<stdio.h>

int main(void) {
    int num, students, code;
    float p1, p2, p3;
    printf("How many students will be evaluated? ");
    scanf("%d", &students);
    for (num = 0; num < students; ++num) {
        scanf("%d%f%f%f", &code, &p1, &p2, &p3);
        printf("\nStudent %d grade is %2.2f.", code, (2 * p1 + 4 * p2 + 4 * p3) / 10 );
    } 
    return 0;
}
