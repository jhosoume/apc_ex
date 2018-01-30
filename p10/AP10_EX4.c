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
    getchar();
    return num;
    
}

void getName(char name[]) {
    printf("Enter student name ");
    scanf("%[^\n]s%*c", name);
}

int getCode() {
    int code;
    printf("Enter student code ");
    scanf("%d", &code);
    return code;
}

void writeGrades(FILE *fwrite, int num_students, int name_size) {
    int indx, n_grades = 3, grade, code;
    float grades[n_grades];
    char name[name_size];
    for (indx = 0; indx < num_students; ++indx) {
        getName(name);
        code = getCode();
        fprintf(fwrite, "%s %d ", name, code);
        printf("Give three for student %d ", code);
        for (grade = 0; grade < n_grades; ++grade) {
            scanf("%f", &grades[grade]);
            getchar();
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
    fp = fopen(file_name, "a");
    if (fp == NULL) {
        printf("File %s could not be open", file_name);
        return 0;
    }
    writeGrades(fp, getNStudents(), name_size);
    return 0;
}
