#include <stdio.h>
#include <string.h>

void readAnswers(char answers[]) {
    scanf("%[^\n]s%*c", answers);
}

int getNumStudents() {
    int num;
    printf("Enter the number of students: ");
    scanf("%d", &num);
    getchar();
    return num;
}

int getGrade(char answers[], char key[], int size) {
    int indx, grade = 0;
    for (indx = 0; indx < size; ++indx) {
        if(answers[indx] == key[indx])
            ++grade;
    }
    return grade;
}


int main() {
    int test_size = 10, num_students, student, max_grade = 0, grade;
    /* One extra char to store \0*/
    char result[test_size + 1], answer[test_size + 1]; 
    printf("Provide the answer key ");
    readAnswers(result);
    num_students = getNumStudents();
    for (student = 0; student < num_students; ++student) {
        printf("Give student %d answers ", student + 1);
        readAnswers(answer);
        grade = getGrade(answer, result, test_size);
        if (grade > max_grade)
            max_grade = grade;
    }
    printf("The greatest grade was %d\n", max_grade);
    return 0;
}
