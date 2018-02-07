#include <stdio.h>

#define clear() printf("\033[H\033[J")
#define N_LINES 15
#define N_COLUMNS 5

void printTetris();
void printDefeat();
void printVictory();
void printFrame();
void showScreen();
void cleanScreen(int total_points, char game[N_LINES][N_COLUMNS]);
