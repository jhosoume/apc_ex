#include <stdio.h>

void readVec(int seq[], int size, char name) {
    int indx;
    printf("Give values for vector %c ", name);
    for (indx = 0; indx < size; ++indx) {
        scanf("%d", &seq[indx]);
    }
}

int uni(int v1[], int v2[], int un[], int size) {
    int indx, indx2, flag, un_size = size;
    for (indx = 0; indx < size; ++indx) {
        un[indx] = v1[indx];
    }

    for (indx = 0; indx < size; ++indx) {
        for (indx2 = 0, flag = 1; indx2 < size; ++indx2) {
            if (v2[indx] == v1[indx2]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            un[un_size] = v2[indx]; 
            ++un_size;
        }
    }
    return un_size;
}

int intersec(int v1[], int v2[], int intersec[], int size) {
    int indx, indx2, inter_size = 0;
    for (indx = 0; indx < size; ++indx) {
        for (indx2 = 0; indx2 < size; ++indx2) {
            if (v1[indx] == v2[indx2]) {
                intersec[inter_size] = v1[indx]; 
                ++inter_size;
                break;
            }
        }
    }
    return inter_size;
}

void printVec(int seq[], char name, int size) {
    int indx;
    printf("Vec %c is: \n", name);
    for (indx = 0; indx < size; ++indx) {
        printf("%d ", seq[indx]);
    }
    printf("\n");
}

int main() {
    int size = 10;
    int vec_x[size], vec_y[size], un[2 * size], inter[size];
    int un_size, inter_size;
    readVec(vec_x, size, 'X');
    readVec(vec_y, size, 'Y');
    un_size = uni(vec_x, vec_y, un, size);
    printVec(un, 'U', un_size);
    inter_size = intersec(vec_x, vec_y, inter, size);
    printVec(inter, 'I', inter_size);
    return 0;
}
