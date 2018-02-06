#include <stdio.h>

#define clear() printf("\033[H\033[J")

void printFrame();
void showScreen();
void cleanScreen(int total_points, int nlines, int ncolumns, char game[nlines][ncolumns]);
