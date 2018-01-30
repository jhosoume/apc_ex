#include <stdio.h>
#include <string.h>

void getFileName(char file_name[], int size, char mode) {
    printf("Enter the name of the file %c: ", mode);
    scanf("%[^\n]s%*c", file_name);
    getchar();
}

void getName(FILE *fread, char name[]) {
    fscanf(fread, "%[^\n]s%*c", name);
}

int getCode(FILE *fread) {
    int code;
    fscanf(fread, "%d", &code);
    return code;
}

void getGrades(FILE *fread, int num_grades, float grades[num_grades]) {
    int indx;
    for (indx = 0; indx < num_grades; ++indx) {
        fscanf(fread, "%f", &grades[indx]);
    }
}

float mean(int num_grades, float grades[num_grades]) {
    int indx;
    float sum;
    for (indx = 0; indx < num_grades; ++indx) {
        sum += grades[indx];
    }
    return sum/num_grades;
}

int getNStudents() {
    int num;
    printf("How many students willl have their grades stored? ");
    scanf("%d", &num);
    getchar();
    return num;

}

void writeMeans(FILE *fwrite, FILE *fread, int name_size) {
    int n_grades = 3, code;
    float grades[n_grades];
    char name[name_size];
    while (fscanf(fread, "%s%d%f%f%f", name, &code, &grades[0], &grades[1], &grades[2]) > 0) {
        printf("NAME: %s CODE: %d\n", name, code);
        fprintf(fwrite, "%d %f\n", code, mean(n_grades, grades));
        printf("MEAN: %f\n", mean(n_grades, grades));
    }
}

int main() {
    int name_size = 30;
    FILE *fgrades, *fmeans;
    char grades_file[name_size], mean_file[name_size];
    getFileName(grades_file, name_size, 'r');
    getFileName(mean_file, name_size, 'w');
    fgrades = fopen(grades_file, "r+");
    if (fgrades == NULL) {
        printf("File %s could not be open.", grades_file);
        return 0;
    }
    fmeans = fopen(mean_file, "w");
    writeMeans(fmeans, fgrades, name_size);
    return 0;
}
