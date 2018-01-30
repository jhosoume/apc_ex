#include <stdio.h>
#include <string.h>

void readString(char phrase[]) {
    printf("Enter the name to be inverted ");
    scanf("%[^\n]s%*c", phrase);
}

void invert(char s1[], char s2[]) {
    int indx, size = strlen(s1);
    for (indx = 0; indx < size; ++indx) {
        s2[size - 1 - indx] = s1[indx];
    }
}


int main() {
    int size = 21;
    char name[size], inverted[size];
    readString(name);
    invert(name, inverted);
    printf("Inverted: %s", inverted);
    return 0;
}
