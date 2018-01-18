#include <stdio.h>

void read(int *code, float *n1, float *n2, float *n3) {
    printf("Provide student code and three grades ");
    scanf("%d%f%f%f", code, n1, n2 ,n3);
}

float mean(float n1, float n2, float n3) {
    return (3 * (n1 + n2) + 4 * n3 ) / 10;
}

int main(void) {
    int n_students, student, code;
    float n1, n2, n3;
    printf("How many students will be evaluated? ");
    scanf("%d", &n_students);

    for (student = 1; student <= n_students; ++student) {
        read(&code, &n1, &n2, &n3);
        printf("The mean of student %d is %2.2f\n", code, mean(n1, n2, n3));
    }

    return 0;
}
