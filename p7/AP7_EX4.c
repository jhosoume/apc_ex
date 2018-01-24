#include <stdio.h>

void readNums(int matrix[], int size) {
    int indx;
    for (indx = 0; indx < size; ++indx) {
        printf("Enter the %dnth number ", indx + 1);
        scanf("%d", &matrix[indx]);
	}
}

void countEvenOdd(int *even, int *odd, int seq[], int size) {
    int indx;
    for (indx = 0; indx < size; ++indx) {
        if (seq[indx] % 2 == 0)
            *even += 1; 
        else
            *odd += 1;
    }
}

int getSize() {
    int size;
    do {
        printf("How many numbers are in the seq? ");
        scanf("%d", &size);
    } while(size > 10000);
    return size;
}


int main(void) {
    int num_even = 0, num_odd = 0, size;
    while(1) {
        size = getSize();
        if (size < 0)
            break;
        int values[size];
        readNums(values, size);
        countEvenOdd(&num_even, &num_odd, values, size);
        printf("There are %d even numbers and %d odd numbers in the sequence.\n",               num_even, num_odd);
		num_even = num_odd = 0;
    }
    return 0;
}
