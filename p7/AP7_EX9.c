#include <stdio.h>

float mean(float nums[], int size) {
    float sum = 0;
    int indx;
    for (indx = 0; indx < size; ++indx) {
        sum += nums[indx];
    }
    return sum/size;
}

void readGrades(float means[], int num) {
    int indx;
    float grades[2];
    for (indx = 0; indx < num; ++indx) {
        printf("Give two grades for the %d-nth student ", indx + 1);
        scanf("%f%f", &grades[0], &grades[1]);
        means[indx] = mean(grades, 2);
        printf("Student %d, has grades %2.2f and %2.2f -> mean grade is %2.2f\n", indx + 1, grades[0], grades[1], means[indx]);
    }
}

int approved(float grades[], int size) {
    int indx, sum = 0;
    for (indx = 0; indx < size; ++indx) {
        if (grades[indx] >= 7.0)
            ++sum;
    }
    return sum;
}

int main() {
    int num_students = 7, n_approved;
    float grades[num_students];
    readGrades(grades, num_students);   
    n_approved = approved(grades, num_students);
    printf("Class -> Mean Grade: %2.2f | Approved %d | Reproved %d\n", 
                mean(grades, num_students), n_approved, num_students - n_approved);
    return 0;
}
