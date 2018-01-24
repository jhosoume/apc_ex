#include <stdio.h>

void readValues(int seq[]) {
    int indx;
    printf("Enter 9 values ");
    for (indx = 0; indx < 9; ++indx) {
        scanf("%d", &seq[indx]);
    }
}

void findNegatives(int seq[]) {
    int indx;
    for (indx = 0; indx < 9; ++indx) {
        if(seq[indx] < 0)
            printf("Number %d is in %d\n", seq[indx], indx + 1);
    }
}

int main() {
    int values[9];
    readValues(values);
    findNegatives(values);

    return 0;
}
