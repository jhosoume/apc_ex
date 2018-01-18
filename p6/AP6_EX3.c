#include <stdio.h>
#include <math.h>

void roots(float a, float b, float c, float *x1, float *x2, int *n_root) {
    float delt = b * b - 4 * a * c;
    if (delt > 0) {
        *n_root = 2;
        *x1 = (-b + sqrt(delt)) / (2 * a);
        *x2 = (-b - sqrt(delt)) / (2 * a);
    } else if (delt == 0) {
        *n_root = 1;
        *x1 = -b  / (2 * a);
        *x2 = *x1;
    } else {
        *n_root = 0;
    }
}

int main(void) {
    int n_root;
    float a, b, c, x1, x2;

    printf("Give the three coeficients of the second degree equation ");
    scanf("%f%f%f", &a, &b, &c);
    roots(a, b, c, &x1, &x2, &n_root);
    if (n_root == 2) 
        printf("Equation has two real roots, %g and %g", x1, x2);
    else if (n_root == 1) 
        printf("Equation has one real root, %g", x1);
    else
        printf("Equation has no real root.");

    return 0;
}
