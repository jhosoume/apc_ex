#include <stdio.h>

void read15(int seq[]) {
    int indx;
    printf("Enter 15 values ");
    for(indx = 0; indx < 15; ++indx) {
        scanf("%d", &seq[indx]);
    }
}

void removeZeros(int seq[]) {
    int indx;
    for(indx = 0; indx < 15; ++indx) {
        if (seq[indx] == 0) {
            seq[indx] = -1;
        }
    }
}

void printSeq(int seq[]) {
    int indx;
    for(indx = 0; indx < 15; ++indx) {
        if (seq[indx] != -1) {
            printf("%d ", seq[indx]);
        }
    }
}

int main() {
    int values[15];
    read15(values);
    removeZeros(values);
    printSeq(values);
    return 0;
}
