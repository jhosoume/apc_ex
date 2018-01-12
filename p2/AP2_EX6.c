#include<stdio.h>

float biggest(float n1, float n2, float n3) {
    if (n1 > n2 && n1 > n3)
        return n1;
    else if (n2 > n3)
        return n2;
    else
        return n3;
}

int main(void) {
    float l1, l2, l3, bigger;

    printf("Give the sides of a possible triangle ");
    scanf("%f%f%f", &l1, &l2, &l3);

    bigger = biggest(l1, l2, l3);
    if ((l1 < l2 + l3) && (l2 < l1 + l3) && (l3 < l1 + l2)) {
        if (bigger * bigger == (l1 * l1 + l2 * l2 + l3 * l3 - bigger * bigger)) 
            printf("\nIt is a triangle rectangle");
        else
            printf("\nIt is just a triangle");
    } else 
        printf("\nIt is not a triangle.");
    return 0;
}

