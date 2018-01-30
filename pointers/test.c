#include <stdio.h>

int main(void) {
    int n, indx;
    printf("Give number of values "); 
    scanf("%d", &n);

    int values[n];
    for(indx = 0; indx < n; ++indx) {
        values[indx] = indx + 1;
    }

    for(indx = 0; indx < n; ++indx) {
        printf("Value in indx %d is %d\n", indx + 1, values[indx]);
    }

    return 0;
}
