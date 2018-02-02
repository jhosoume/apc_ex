#include <stdio.h>

float mdc(int num1, int num2) {
    if ((num1 >= num2) && (num1 % num2 == 0))
        return num2;
    else if (num1 < num2)
        return mdc(num2, num1);
    else 
        return mdc(num2, num1 % num2);
}

void readNums(int *num1, int *num2) {
    printf("Enter numbers to calculate mdc(x, y): ");
    scanf("%d %d", num1, num2);
}

int main() {
	int num1, num2, result;
    readNums(&num1, &num2);
	result = mdc(num1, num2);
    printf("Result of mdc(%d, %d) = %d", num1, num2, result);
    return 0;
}
