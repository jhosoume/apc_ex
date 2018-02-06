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

void cleanScreen(int total_points, int nlines, int ncolumns, char game[nlines][ncolumns]) {
    int line, column;
    clear();
    printf("  +--------------------+      PONTUACAO: %d\n",total_points);
    for (line = 0; line < nlines; ++line) {
      if (line == 6) {
          printf("=>+");
      } else {
          printf("  |");
      }
      for (column = 0; column < ncolumns; ++column) {
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

