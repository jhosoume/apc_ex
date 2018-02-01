#include <stdio.h>
/*********************************************************
* Descricao : ler e imprimir os dados de n registros.
* n deve ser lido e ser menor do que 10.
* O Programa principal somente chama funcoes para ler
* e mostrar os dados
* Entrada: nome, codigo, sexo, cargo
* Saida:   nome, codigo, sexo, cargo
**********************************************************/
typedef  struct {
     int codigo;
     float salario;
     char nome[50], sexo[10], endereco[50], cargo[50];
} tipoDadosDeFuncionario;

void ledados (tipoDadosDeFuncionario *vetfunc, int *n) {
    int i;
    printf("Informe o nro de funcionarios: ");
    scanf ("%d",n);
    while ((*n<1) || (*n>10)) {
		printf("\nERRO! O nro de funcionarios deve ser entre 1 e 10.");
        printf("\nTecle <enter> para continuar.");
        getchar(); 
        printf("\nInforme o nro de funcionarios: ");
        scanf ("%d",n);
        getchar(); 
    }
    for (i = 0; i < (*n); i++ ) {
		printf("\nInforme o nome: ");
		scanf("%s", vetfunc[i].nome);
		printf("Informe o cod: ");
		scanf("%d", &vetfunc[i].codigo);
		printf("Informe o sexo: ");
		scanf("%s", vetfunc[i].sexo);
		printf("Informe o cargo: ");
		scanf("%s", vetfunc[i].cargo);
	}
}

void mostradados (tipoDadosDeFuncionario *vetfunc, int n) {
    int i;
    for (i = 0; i<n; i++ ) {
        printf("\n\nNome: %s",vetfunc[i].nome);
        printf("\nCod: %d",vetfunc[i].codigo);
        printf("\nSexo: %s",vetfunc[i].sexo);
        printf("\nCargo: %s",vetfunc[i].cargo);
}
}
int main() {
     tipoDadosDeFuncionario dadosDeFunc[10];
     int nrofunc;
     ledados(dadosDeFunc,&nrofunc);
     mostradados(dadosDeFunc,nrofunc);
     getchar();
     getchar();
}
