#include<stdio.h>

int main(void) {
    int days;
    printf("Enter your age in days ");
    scanf("%d", &days);
    printf("You have %d years, %d months and %d days",
        days/365, (days%365)/30, (days%365)%30);
    return 0;
}
