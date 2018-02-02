#include <stdio.h>

int X(int n, int m) {
	printf("Entrou na funcao com n= %d e m=%d",n,m);
	getchar();
	if ((n == m) || (n == 0)) {
		printf("Os valores de n e m se igualaram. Parou de chamar ela mesmo e retornou 1.");
		getchar(); 
		return 1;
	} else {
		printf("A funcao vai chamar ela mesmo, com n = %d e m = %d",n-1,m);
		getchar();
		return n + X(n - 1, m);
	}
}

int main() {
	printf("Resultado da funcao X: %d ",X(5,3));
	getchar();
    return 0;
}
