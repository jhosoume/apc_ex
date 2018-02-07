#include <stdio.h>
#include <string.h>
#include <time.h>
#include <screen.h>

#define MAX_SEQ 70
#define N_LINES 15
#define N_COLUMNS 5
#define MAX_LINE 6

typedef struct {
    char orientation;
    char rep;
    int line;
    int column;
    int size;
} piece;

void start();
int checkBoundaries(piece c_piece, int nlines, int ncolumns);
void addPiece(piece c_piece, int nlines, int ncolumns, char game[nlines][ncolumns]);
void erasePiece(piece c_piece, int nlines, int ncolumns, char game[nlines][ncolumns]);
char getCommand();
int gameLoop(int num_pieces, piece sequences[MAX_SEQ], int nlines, int ncolumns, char game[N_LINES][N_COLUMNS]);
int defineAction(char command, piece *c_piece, char game[N_LINES][N_COLUMNS]);
void endGame(int stats);
void moveRight(piece *c_piece, char game[N_LINES][N_COLUMNS]);
void moveLeft(piece *c_piece, char game[N_LINES][N_COLUMNS]);
void rotate(piece *c_piece, char game[N_LINES][N_COLUMNS]);
void fall(piece *c_piece, char game[N_LINES][N_COLUMNS], int points);
int freeLine(char orientation, int column, int size, char game[N_LINES][N_COLUMNS]);
void checkCompletedLines(char game[N_LINES][N_COLUMNS]);
int checkLimitReached();
void startMessage();
void loseMessage();
void winMessage();
int readSequences(char file_name[], piece sequences[]);
void cleanActionSpace(char game[][N_COLUMNS]);
void printSequences(int num_seq, piece sequences[num_seq]);
void checkMatrix(int nlines, int ncolumns, char game[nlines][ncolumns]);
void fillLine(int bline, int eline, char game[N_LINES][N_COLUMNS]);
void emptyGame(int nlines, int ncolumns, char game[nlines][ncolumns]);
int gameLoop(int num_pieces, piece sequences[MAX_SEQ], int nlines, int ncolumns, char game[N_LINES][N_COLUMNS]);

