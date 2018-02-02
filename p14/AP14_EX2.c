#include <stdio.h>

int fat(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fat(n - 1);
    }
}

int readNum() {
    int num;
    do {
        printf("Enter number to calculate the factorial, number must an integer equal or greater than 0: ");
        scanf("%d", &num);
    } while (num < 0);
    return num;
}

int main() {
    int num, result;
    num = readNum();
    result = fat(num); 
    printf("The %d! = %d\n", num, result);
    return 0;
}
