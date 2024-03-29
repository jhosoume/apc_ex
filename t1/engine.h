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
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <screen.h>

#define MAX_SEQ 70
#define MAX_LINE 6

typedef struct {
    char orientation;
    char rep;
    int line;
    int column;
    int size;
} piece;

void start();
int checkBoundaries(piece c_piece);
void addPiece(piece c_piece, char game[N_LINES][N_COLUMNS]);
void erasePiece(piece c_piece, char game[N_LINES][N_COLUMNS]);
char getCommand();
int gameLoop(int num_pieces, piece sequences[MAX_SEQ], char game[N_LINES][N_COLUMNS]);
int defineAction(char command, piece *c_piece, char game[N_LINES][N_COLUMNS], int *points);
void endGame(char game[N_LINES][N_COLUMNS], int points);
void moveRight(piece *c_piece, char game[N_LINES][N_COLUMNS]);
void moveLeft(piece *c_piece, char game[N_LINES][N_COLUMNS]);
void rotate(piece *c_piece, char game[N_LINES][N_COLUMNS]);
void fall(piece *c_piece, char game[N_LINES][N_COLUMNS]);
int freeLine(char orientation, int column, int size, char game[N_LINES][N_COLUMNS]);
void checkCompletedLines(char game[N_LINES][N_COLUMNS], int *points);
int checkLimitReached(char game[N_LINES][N_COLUMNS]);
void startMessage();
void loseMessage();
void winMessage(int points);
int readSequences(char file_name[], piece sequences[]);
void cleanActionSpace(char game[][N_COLUMNS]);
void printSequences(piece sequences[MAX_SEQ]);
void checkMatrix(char game[N_LINES][N_COLUMNS]);
void fillLine(int bline, int eline, char game[N_LINES][N_COLUMNS]);
void emptyGame(char game[N_LINES][N_COLUMNS]);
void cleanEnter();
