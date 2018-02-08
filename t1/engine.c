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
 * Versão do compilador: gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.5)
 * Descricao: Jogo simplificado de Tetris, implementado apenas com as bibliotecas e funcoes basicas da linguagem C
*/

#include "engine.h"

void start() {
    /* Main function of the engine. */
	char game[N_LINES][N_COLUMNS];
    int n_pieces, points;
	piece sequences[MAX_SEQ]; 
    n_pieces = readSequences("sequences.txt", sequences);
    clear();
    printTetris();
    startMessage();
    /* Empty game fills matrix with empty spaces. */
    emptyGame(game);
    points = gameLoop(n_pieces, sequences, game);
    endGame(game, points);
    
}


void checkMatrix(char game[N_LINES][N_COLUMNS]) {
    /* Functin used only for debuggig purposes.
     * Prints stored character of every line and column. */
    int line, column;
    for (line = 0; line < N_LINES; ++line) {
        for (column = 0; column < N_COLUMNS; ++column) {
            printf("Line: %d Columns: %d Value: %c\n", line, column, game[line][column]);
        }
    }
}


int checkBoundaries(piece c_piece) {
    /* Checks if piece is inside the game matrix. Return 1 if inside and 0 otherwise. */
    if (c_piece.orientation == 'h' && c_piece.column + c_piece.size > N_COLUMNS) {
        return 0;
    } else if (c_piece.orientation == 'v' && c_piece.line + c_piece.size > N_LINES) {
        return 0;
    } else if (c_piece.line < 0) {
        return 0;
    } else if ( c_piece.column < 0) {
        return 0;
    } else if (c_piece.column > N_COLUMNS - 1) {
        return 0;
    } else if (c_piece.line > N_LINES) {
        return 0;
    } else {
        return 1;
    }
}

void addPiece(piece c_piece, char game[N_LINES][N_COLUMNS]) {
    /* Adds piece to the game matrix in two ways, accordingly to piece orientation. */
    int line, column;
    if (checkBoundaries(c_piece)) {
        if (c_piece.orientation == 'v') {
            for (line = c_piece.line; line < c_piece.line + c_piece.size; ++line) {
                game[line][c_piece.column] = c_piece.rep;
            }
        } else {
            for (column = c_piece.column; column < c_piece.column + c_piece.size; ++column) {
                game[c_piece.line][column] = c_piece.rep;
            }
        }
    }
}

void erasePiece(piece c_piece, char game[N_LINES][N_COLUMNS]) {
    /* Removes piece from game matrix. Usually used to refresh piece position. */
    int line, column;
    if (checkBoundaries(c_piece)) {
        if (c_piece.orientation == 'v') {
            for (line = c_piece.line; line < c_piece.line + c_piece.size; ++line) {
                game[line][c_piece.column] = ' ';
            }
        } else {
            for (column = c_piece.column; column < c_piece.column + c_piece.size; ++column) {
                game[c_piece.line][column] = ' ';
            }
        }
    }
}

int gameLoop(int num_pieces, piece sequences[MAX_SEQ], char game[N_LINES][N_COLUMNS]) {
    /* Gets commands while the game is not over (victory or defeat) */
    int times = 0, count;
    int points = 0;
    char command;
    while (times < num_pieces && checkLimitReached(game)) {
        addPiece(sequences[times], game);
        cleanScreen(points,  game);
        command = getCommand(); 
        count = defineAction(command, &sequences[times], game, &points);
        times += count;
    }
    return points;
}

void endGame(char game[N_LINES][N_COLUMNS], int points) {
    if (!checkLimitReached(game)) {
        loseMessage();
    } else {
        winMessage(points);
    }
}

void moveRight(piece *c_piece, char game[N_LINES][N_COLUMNS]) {
    piece t_piece = *c_piece;
    erasePiece(*c_piece, game);
    t_piece.column++;
    if (checkBoundaries(t_piece)) {
        c_piece->column++;
    }
    addPiece(*c_piece, game);
}

void moveLeft(piece *c_piece, char game[N_LINES][N_COLUMNS]) {
    piece t_piece = *c_piece;
    erasePiece(*c_piece, game);
    t_piece.column--;
    if (checkBoundaries(t_piece)) {
        c_piece->column--;
    }
    addPiece(*c_piece, game);
}

void rotate(piece *c_piece, char game[N_LINES][N_COLUMNS]) {
    piece t_piece = *c_piece;
    erasePiece(*c_piece, game);
    if (c_piece->orientation == 'h') {
        t_piece.orientation = 'v';
        if (checkBoundaries(t_piece)) {
            c_piece->orientation = 'v';
        }
    } else {
        /* rotation from vertical to horizontal can reach board line. */
        /* usually rotation is counter clockwise, but if close to the right border,
         * the piece rotates in a clockwise manner. */
        t_piece.orientation = 'h';
        if (checkBoundaries(t_piece)) {
            c_piece->orientation = 'h';
        } else if (t_piece.column + t_piece.size > N_COLUMNS) {
            t_piece.column -= (t_piece.size - 1);
            if (checkBoundaries(t_piece)) {
                c_piece->orientation = 'h';
                /* for ratotation to be clockwise, start column must be changed */
                c_piece->column -= (c_piece->size - 1);
            }
        }
    }
    addPiece(*c_piece, game);
}

void fall(piece *c_piece, char game[N_LINES][N_COLUMNS]) {
    int free_line; 
    int column, line;
    erasePiece(*c_piece, game);
    free_line = freeLine(c_piece->orientation, c_piece->column, c_piece->size, game);
    if (c_piece->orientation == 'h') {
        for (column = c_piece->column; column < c_piece->column + c_piece->size; ++column) {
            game[free_line][column] = c_piece->rep;
        }
    } else {
        for (line = free_line; line > free_line - c_piece->size; --line) {
            game[line][c_piece->column] = c_piece->rep;
        }
    }
}

int freeLine(char orientation, int column, int size, char game[N_LINES][N_COLUMNS]) {
    /* Column is different from column_indx, column is the current position of the piece to fall. */
    int line, column_indx;
    /* Finds a free position for the piece to fall. If find char in the current line, return previous line. */
    if (orientation == 'v') {
        for (line = MAX_LINE; line < N_LINES; ++line) {
            if (game[line][column] != ' ') {
                return line - 1;
            }
        }
        return line - 1;
    } else {
        for (line = MAX_LINE; line < N_LINES; ++line) {
            for (column_indx = column; column_indx < column + size; ++column_indx) {
                if (game[line][column_indx] != ' ') {
                    return line - 1;
                }
            }
        }
        return line - 1 ;
    }
}

void checkCompletedLines(char game[N_LINES][N_COLUMNS], int *points) {
    int line, column, flag, line2; 
    for (line = N_LINES - 1; line > MAX_LINE; --line) {
        flag = 1;
        for (column = 0; column < N_COLUMNS; ++column) {
            if (game[line][column] == ' ') {
                flag = 0;
                break;
            }
        }
        if (flag) {
            *points += 100;
            fillLine(line, line, game);
            cleanScreen(*points, game);
            for (line2 = line; line2 > MAX_LINE; --line2) {
                for (column = 0; column < N_COLUMNS; ++column) {
                    game[line2][column] = game[line2 - 1][column];
                }
            }
            /* Since moved all lines up, need to check the current line again, so back one line */
            ++line;
        }
    }
}

int checkLimitReached(char game[N_LINES][N_COLUMNS]) {
    /* Check if any piece is inserted in the max area. */
    int column;
    for (column  = 0; column < N_COLUMNS; ++column) {
        if (game[MAX_LINE][column] != ' ') {
            return 0;
        }
    }
    return 1;
}



void startMessage() {
    printf("Tecle <enter> para iniciar o jogo");
    getchar();
}

void loseMessage() {
    clear();
    printDefeat();
    printf("*** YOU LOSE!!! Tecle <enter> para sair");
    getchar();
}

void winMessage(int points) {
    clear();
    printVictory();
    printf("*** PARABENS!!! VOCE CHEGOU AO FIM DO JOGO COM %d PONTOS\n", points);
    cleanEnter();
    getchar();
}

int permitedCommands(char command) {
    /* Get if the command in valid. If valid, return 0, if not return 1. */
    switch (command) {
        case 'r':
        case 'd':
        case 'D':
        case 'R':
        case 'e':
        case 'E':
        case 'c':
        case 'C':
        case 'q':
        case 'Q':
            return 0;
        default:
            return 1;
    }
}

char getCommand() {
    char command;
    printf("R-rotar D-direita E-esquerda C-cair\n");
    printf("ACAO: ");
    do {
        scanf("%c", &command);
        fflush(stdout);
    } while (permitedCommands(command));
    return command;
}

int defineAction(char command, piece *c_piece, char game[N_LINES][N_COLUMNS], int *points) {
    switch (command) {
        case 'r':
        case 'R':
            rotate(c_piece, game);
            return 0;
        case 'd':
        case 'D':
            moveRight(c_piece, game);
            return 0;
        case 'e':
        case 'E':
            moveLeft(c_piece, game);
            return 0;
        case 'c':
        case 'C':
            fall(c_piece, game);
            checkCompletedLines(game, points);
            return 1;
        case 'q':
        case 'Q':
            return 0;
        default:
            return 0;
    }
}


int readSequences(char file_name[], piece sequences[]) {
    /* All read sequences are stored as structs. */
	FILE *fp; 
	char line[7];
	int nseq = 0; 
	fp = fopen(file_name, "r"); 
	while (fscanf(fp,"%s", line) > 0) {
        sequences[nseq].orientation = 'v';
        sequences[nseq].rep = line[0];
        sequences[nseq].line = 0;
        sequences[nseq].column = N_COLUMNS / 2;
        sequences[nseq].size = strlen(line);
        ++nseq;
	}
	fclose(fp); 
    return nseq;
}

void printSequences(piece sequences[MAX_SEQ]) {
    /* Used for debugging purposes. Prints all read sequences. */
    int indx;
    for (indx = 0; indx < MAX_SEQ; ++indx) {
        printf("Seq %d ->", indx);
        printf("rep %c ", sequences[indx].rep);
        printf("size %d\n", sequences[indx].size);
    }
    
}

void emptyGame(char game[N_LINES][N_COLUMNS]) {
    /* Fills matrix with empty spaces. */
    int line,column;
    for (line = 0; line < N_LINES; ++line) {
        for (column = 0; column < N_COLUMNS; ++column) {
           game[line][column] = ' '; 
        }
    }
}

void fillLine(int bline, int eline, char game[N_LINES][N_COLUMNS]) {
    /* Fills defined lines of the matrix with X. */
    int line, column;
    for (line = bline; line <= eline; ++line) {
        for (column = 0; column < N_COLUMNS; ++column) {
            game[line][column] = 'X';
        }
    }
    sleep(1);
}

void cleanActionSpace(char game[][N_COLUMNS]) {
    emptyGame(game);
}

void cleanEnter() {
    fseek(stdin,0,SEEK_END);
}
