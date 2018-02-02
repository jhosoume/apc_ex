#include <stdio.h>

int fib(int num) {
    if (num == 0)
        return 0;
    else if (num == 1) 
        return 1;
    else
        return fib(num - 1) + fib(num - 2);
}

int readNum() {
    int num;
    printf("Enter the number to calculate Fibonacci sum: ");
    scanf("%d", &num);
    return num;
}

int main() {
	int num, result; 
    num = readNum();
	result = fib(num);
    printf("The Fibonacci of %d is %d", num, result);
    return 0;
}
