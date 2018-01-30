#include "screen.h"

void printFrame() {
    int line;
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

/*void cleanScreen(int total_points) {
    int line, column;
    printf("  +--------------------+      PONTUACAO: %d\n",total_points);
    for (line = 0; line < 15; ++line) {
      if (line == 6)
          printf("=>+");
      else
          printf("  |");
      for (column = 0; column < 20; ++column)
          printf("%c",JOGO[i][j]); 
      if (line == 6)
          printf("+<=⧵n");
      else
          printf("|⧵n");
    }
    printf("  +--------------------+\n");
    printf("R-rotar D-direita E-esquerda C-cair\n");
    printf("ACAO: ");
}*/

