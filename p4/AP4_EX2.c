/*  Description: print numbers 1 to 5, five times.
    Input: None
    Output: 1
     1 2
     1 2 3   
     1 2 3 4
     1 2 3 4 5    */
#include <stdio.h>
int main(void) {
    int num, time ;
    for (time = 1; time <= 5; ++time) {
        num = 0;
		do {
			++num;
			printf("%d ", num);
  		} while (num < time);
        printf("\n");
    }
    getchar();
    return(0);
}
