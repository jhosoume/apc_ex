#include <stdio.h>
#include <string.h>

void readNumbers(char numbers[]) {
    printf("Enter numbers ");
    scanf("%s", numbers);
}

int convertToInt(char number_s[]) {
    int size = strlen(number_s), indx, mult = 1, sum = 0;
    for (indx = 1; indx <= size; ++indx) {
       sum += (number_s[size - indx]- '0') * mult; 
       mult *= 10;
    }
    return sum;
}

int main() {
    int size = 20;
    char number[size];
    readNumbers(number);
    printf("The number is %d\n", convertToInt(number));
    return 0;
}
