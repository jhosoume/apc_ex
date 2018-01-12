#include<stdio.h>

int main(void) {
    int input;
    printf("Entre um valor: ");
    scanf("%d", &input);
    printf("O sucessor é %d, e o antecessor é %d", input + 1, input - 1);
    return 0;
}
