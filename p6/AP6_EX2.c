#include <stdio.h>

int biggest(int n1, int n2, int n3) {
    if (n1 > n2 && n1 > n3)
        return n1;
    else if (n2 > n3)
        return n2;
    else 
        return n3;
}

int smallest(int n1, int n2, int n3) {
    if (n1 < n2 && n1 < n3)
        return n1;
    else if (n2 < n3)
        return n2;
    else 
        return n3;
}

void limits(int n1, int n2, int n3, int *bigger, int *smaller) {
    *bigger = biggest(n1, n2, n3);
    *smaller = smallest(n1, n2, n3);
}

int main(void) {
    int n1, n2, n3;
    int smaller, bigger;

    printf("Enter three numbers ");
    scanf("%d%d%d", &n1, &n2, &n3);
    limits(n1, n2, n3, &bigger, &smaller);
    printf("Of the three numbers %d, %d and %d, the biggest is %d, and the smallest is %d",
        n1, n2, n3, bigger, smaller);
    return 0;
}
