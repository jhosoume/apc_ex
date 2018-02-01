#include <stdio.h>
/*********************************************************
* Descricao : ler e imprimir os dados de UM registro.
* Entrada: nome, idade, salario
* Saida:   nome, idade, salario
**********************************************************/
typedef  struct {
     int idade;
     float salario;
     char nome[30];
} tipoDadosFunc;
int main() {
     tipoDadosFunc dadosfunc;
     printf("Informe o nome: ");
     scanf("%s", dadosfunc.nome);
     printf("Informe a idade: ");
     scanf("%d", &dadosfunc.idade);
     printf("Informe o salario: ");
     scanf("%f", &dadosfunc.salario);
     printf("\n\nDADOS INFORMADOS");
     printf("\nNome: %s",dadosfunc.nome);
     printf("\nIdade: %d",dadosfunc.idade);
     printf("\nSalário: %.2f",dadosfunc.salario);
     getchar();
     getchar(); 
}
