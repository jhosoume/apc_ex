#include <stdio.h>

int fun(int n) {
    if (n % 5 == 0) {
        return 0;
    }
    return 1;
}

int main() {
    int n, r;
    printf("Informe um número ");
    scanf("%d", &n);
    r = fun(n);
    if(r)
        printf("Retorno foi 1\n");
    else
        if (r == 0) {
            printf("Retorno foi 0\n");
        } else {
            printf("Retorno foi -1\n");
        }
    return 0;
}
