#include <stdio.h>

float pot(float base, int exp) {
    if (exp == 0)
        return 1;
    else if (exp > 0)
        return base * pot(base, exp - 1);
    else 
        return (1/base) * pot(base, exp + 1);
}

void readNums(float *base, int *exp) {
    printf("Enter numbers to calculate pow(base, exp) => base ^ exp: ");
    scanf("%f %d", base, exp);
}

int main() {
	int exp; 
	float base, result;
    readNums(&base, &exp);
	result = pot(base, exp);
    printf("Result of %g ^ %d is %g", base, exp, result);
    return 0;
}
