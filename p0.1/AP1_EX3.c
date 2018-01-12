#include<stdio.h>

int main(void) {
    float factory_cost;
    printf("Factory Cost is ");
    scanf("%f", &factory_cost);
    printf("Final price is %2.2f", factory_cost * 1.73); 
    return 0;
}
