#include <stdio.h>
int main () { 
    int indx, W[5];
	/* Read values and store in a vector. */
    for (indx = 0; indx < 5; ++indx) {
        printf("Type the %d-th number: \n", indx + 1);
        scanf("%d",&W[indx]);
    }
	/* Print values stored in the vector W. */
    for (indx = 0; indx < 5; ++indx) {
        printf("Value stored W[%d] = %d \n", indx + 1, W[indx]);
    }
    getchar();
    return 0;
}
