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

#include <stdio.h>

#define clear() printf("\033[H\033[J")
#define N_LINES 15
#define N_COLUMNS 20

void printTetris();
void printDefeat();
void printVictory();
void printFrame();
void showScreen();
void cleanScreen(int total_points, char game[N_LINES][N_COLUMNS]);
