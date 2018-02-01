#include <stdio.h>
/*********************************************************
* Descricao : ler e imprimir os dados de DEZ registros.
* Entrada: nome, idade, salario
* Saida:   nome, idade, salario
**********************************************************/
typedef  struct {
     int idade;
     float salario;
     char nome[30];
} tipoDadosFunc;

int main() {
     tipoDadosFunc dadosfunc[10];
     int i;
     for (i = 0; i < 10; i++ ) {
           printf("Informe o nome: ");
           scanf("%s", dadosfunc[i].nome);
           printf("Informe a idade: ");
           scanf("%d", &dadosfunc[i].idade);
           printf("Informe o salario: ");
           scanf("%f", &dadosfunc[i].salario);
     }
     printf("\n\nDADOS INFORMADOS");
     for (i = 0; i < 10; i++ ) {
           printf("\n\nNome: %s", dadosfunc[i].nome);
           printf("\nIdade: %d", dadosfunc[i].idade);
           printf("\nSalario: %.2f", dadosfunc[i].salario);
     }
     getchar();
     getchar();
}
