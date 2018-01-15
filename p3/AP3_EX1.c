#include <stdio.h>
/* Description: Print numbers from 1 to 10
 * Input: None
 * Output: 1,2,3,...,10  */
int main() {
    int i;
    printf("Numbers from 1 to 10: ");
    for (i = 1; i < 11; i++) {
        printf("%d\n", i);
    }
    getchar();
    return 0;
}

