#include <stdio.h>

int summing(int num) {
    if (num == 0)
        return 0;
    else 
        return num + summing(num - 1);
}

int readNum() {
    int num;
    printf("Enter the number to calculate the sum: ");
    scanf("%d", &num);
    return num;
}

int main() {
	int num, result; 
    num = readNum();
	result = summing(num);
    printf("Result of sum of %d is %d", num, result);
    return 0;
}
