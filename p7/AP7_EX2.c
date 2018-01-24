#include <stdio.h>

void readNums(int *matrix) {
    int indx;
    for (indx = 0; indx < 6; ++indx) {
        printf("Enter the %d-nth number ", indx + 1);
        scanf("%d", &matrix[indx]);
    }
}

void countEvenOdd(int *even, int *odd, int seq[]) {
    int indx;
    for (indx = 0; indx < 6; ++indx) {
        if (seq[indx] % 2 == 0)
            *even += 1; 
        else
            *odd += 1;
    }
}

int main(void) {
    int values[6], num_even = 0, num_odd = 0;
    readNums(values);
    countEvenOdd(&num_even, &num_odd, values);
    printf("There are %d even numbers and %d odd numbers in the sequence.\n",               num_even, num_odd);
    return 0;
}
