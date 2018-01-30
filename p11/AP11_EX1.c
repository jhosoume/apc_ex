#include <stdio.h>


void readVector(int num, int values[num]) {
    int indx;
    printf("Enter values to be ordered ");
    for (indx = 0; indx < num; ++indx) {
        scanf("%d", &values[indx]);
    }
}

void swap(int *num1, int *num2) {
    int aux;
    aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}

void bubbleSort(int num, int values[num]) {
    int indx, flag;
    do {
        flag = 0;
        for (indx = 0; indx < num - 1; ++indx) {
            if (values[indx] > values[indx + 1]) {
                flag = 1;
                swap(&values[indx], &values[indx + 1]);
            }
        }
    } while (flag);

    
}

void writeVector(int num, int values[num]) {
    int indx;
    printf("Ordered vector is ");
    for (indx = 0; indx < num; ++indx) {
        printf("%d ", values[indx]);
    }
}

int main() {
    int num = 10, values[num];
    readVector(num, values);
    bubbleSort(num, values);
    writeVector(num, values);
    return 0;
}
