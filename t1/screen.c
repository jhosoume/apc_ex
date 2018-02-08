 /*
 * Universidade de Brasilia
 * Instituto de Ciencias Exatas
 * Departamento de Ciencia da Computacao
 * Algoritmos e Programacao de Computadores
 * –
 * 0/2018
 * Aluno(a): Juliana Mayumi Hosoume
 * Matricula: 17/0003078
 * Turma: B
 * Versão do compilador: gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.5)                                            * Descricao: Jogo simplificado de Tetris, implementado apenas com as bibliotecas e funcoes basicas da linguagem C
*/

#include "screen.h"

void printFrame() {
    int line;
    clear();
    printf("  +--------------------+\n");
    for (line = 0; line < 6; ++line) {
        printf("  |                    |\n");
    }
    printf("=>+                    +<=\n");
    for (line = 0; line < 8; ++line) {
        printf("  |                    |\n");/*20 espaços*/
    }
    printf("  +--------------------+\n");
}

void showScreen() {
    printFrame();
}

void cleanScreen(int total_points, char game[N_LINES][N_COLUMNS]) {
    int line, column;
    clear();
    printf("  +--------------------+      PONTUACAO: %d\n",total_points);
    for (line = 0; line < N_LINES; ++line) {
      if (line == 6) {
          printf("=>+");
      } else {
          printf("  |");
      }
      for (column = 0; column < N_COLUMNS; ++column) {
          printf("%c", game[line][column]); 
      }
      if (line == 6) {
          printf("+<=\n");
      } else {
          printf("|\n");
      }
    }
    printf("  +--------------------+\n");
}

void printTetris() {
    printf("  _______   _        _     \n");
    printf(" |__   __| | |      (_)    \n");
    printf("    | | ___| |_ _ __ _ ___ \n");
    printf("    | |/ _ \\ __| '__| / __|\n");
    printf("    | |  __/ |_| |  | \\__ \\ \n");
    printf("    |_|\\___|\\__|_|  |_|___/ \n");
}

void printDefeat() {
	printf("  _____        __           _   \n");
	printf(" |  __ \\      / _|         | |  \n");
	printf(" | |  | | ___| |_ ___  __ _| |_ \n");
	printf(" | |  | |/ _ \\  _/ _ \\/ _` | __|\n");
	printf(" | |__| |  __/ ||  __/ (_| | |_ \n");
	printf(" |_____/ \\___|_| \\___|\\__,_|\\__|\n");
}

void printVictory() {
	printf(" __      ___      _                    \n");
	printf(" \\ \\    / (_)    | |                   \n");
	printf("  \\ \\  / / _  ___| |_  ___  _ __ _   _ \n");
	printf("   \\ \\/ / | |/ __| __|/ _ \\| '__| | | |\n");
	printf("    \\  /  | | (__| |_| (_) | |  | |_| |\n");
	printf("     \\/   |_|\\___|\\__|\\___/|_|   \\__, |\n");
	printf("                                  __/ |\n");
	printf("                                 |___/ \n");
}

