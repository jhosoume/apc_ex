#include <stdio.h>
#include <string.h>

void getFileName(char file_name[], int size) {
    printf("Enter the name of the file to be written ");
    scanf("%[^\n]s%*c", file_name);
}

int getNStudents() {
    int num;
    printf("How many students willl have their grades stored? ");
    scanf("%d", &num);
    return num;
    
}

void writeGrades(FILE *fwrite, int numStudents) {
    int indx, n_grades = 3, grade;
    float grades[n_grades];
    for (indx = 0; indx < numStudents; ++indx) {
        printf("Give three for student %d ", indx);
        for (grade = 0; grade < n_grades; ++grade) {
            scanf("%f", &grades[grade]);
            fprintf(fwrite, "%f ", grades[grade]);
        }
        fprintf(fwrite, "\n");
    }
}

int main() {
    int name_size = 30;
    FILE *fp;
    char file_name[name_size];
    getFileName(file_name, name_size);
    fp = fopen(file_name, "w");
    writeGrades(fp, getNStudents());
    return 0;
}
