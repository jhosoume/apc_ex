#include<stdio.h>

int main(void) {
    int years, months, days;

    printf("Enter your age in years, months and days ");
    scanf("%d %d %d", &years, &months, &days);
    printf("Your age in days %d", years*365 + months*30 + days);

    return 0;
}

