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

int numToFind() {
    int num;
    printf("Enter the number to be found ");
    scanf("%d", &num);
    return num;
}

int searchSeq(int num, int size, int values[size]) {
    int indx;
    for (indx = 0; indx < size; ++indx) {
        if (values[indx] == num) 
            return indx;
    }
    return -1;
}

int searchBin(int num, int size, int values[size]) {
    int beg = 0, end = size - 1, mid;
    while (beg <= end) {
        mid = (beg + end)/2;
        if (num == values[mid]) {
            return mid;
        } else if (num < values[mid]) {
            end = mid - 1;
        } else {
            end = mid + 1;
        }
        printf("B %d E %d M %d\n", beg, end, mid);
    }
    return -1;
}

void outSearch(int indx) {
    if (indx < 0) 
        printf("Number not found in the sequence\n");
    else
        printf("Number is in position %d\n", indx);
}

void writeVector(int num, int values[num]) {
    int indx;
    printf("Ordered vector is ");
    for (indx = 0; indx < num; ++indx) {
        printf("%d ", values[indx]);
    }
    printf("\n");
}

int main() {
    int num = 10, values[num];
    readVector(num, values);
    bubbleSort(num, values);
    writeVector(num, values); 
    outSearch(searchBin(numToFind(), num, values));
    return 0;
}
