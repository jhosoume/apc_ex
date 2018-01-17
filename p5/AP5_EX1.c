#include <stdio.h>
float fat(int x){
    int num;
    float result = 1;
    for (num = 1; num <= x; ++num) {
        result *= num;
    }
   return result;
}

int main(void) {
    int n,k;
    float c;
    printf("Enter a value for n: ");
    scanf("%d",&n);
    printf("\n");
    printf("Enter a value for k: ");
    scanf("%d",&k);
    printf("\n");
    c = fat(n)/(fat(k)*fat(n-k));
    printf("%f\n",c);
    return 0;
}
