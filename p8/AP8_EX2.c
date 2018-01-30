#include <stdio.h>
#include <string.h>

void readString(char code[]) {
    printf("Enter string to be compressed ");
    scanf("%[^\n]s%*c", code);
}

void compress(char input[], char result[]) {
    int repeat, indx = 0, indx2 = 0;
    while (indx < strlen(input)) {
        repeat = 1;
        while (input[indx] == input[indx + 1]) {
            ++repeat;
            ++indx;
        }
        if (repeat == 1) {
            result[indx2] = input[indx];
            ++indx2;
        } else {
            result[indx2] = repeat + '0';
            result[++indx2] = input[indx];
            ++indx2;
        }
        ++indx;
    }
}

int main() {
    char input[25], result[25];
    readString(input);
    compress(input, result);
    printf("OUTPUT: %s", result);
    return 0;
}
