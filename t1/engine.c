#include "engine.h"

void start() {
	char game[N_LINES][N_COLUMNS];
    int n_pieces, points;
	piece sequences[MAX_SEQ]; 
    n_pieces = readSequences("sequences.txt", sequences);
    printTetris();
    startMessage();
    emptyGame(game);
    points = gameLoop(n_pieces, sequences, game);
    endGame(game, points);
    
}


void checkMatrix(char game[N_LINES][N_COLUMNS]) {
    int line, column;
    for (line = 0; line < N_LINES; ++line) {
        for (column = 0; column < N_COLUMNS; ++column) {
            printf("Line: %d Columns: %d Value: %c\n", line, column, game[line][column]);
        }
    }
}


int checkBoundaries(piece c_piece) {
    printf("ENTREI 3\n");
    if (c_piece.orientation == 'h' && c_piece.column + c_piece.size > N_COLUMNS) {
        printf("11111\n");
        return 0;
    } else if (c_piece.orientation == 'v' && c_piece.line + c_piece.size > N_LINES) {
        printf("22222\n");
        return 0;
    } else if (c_piece.line < 0) {
        printf("33333\n");
        return 0;
    } else if ( c_piece.column < 0) {
        printf("44444\n");
        return 0;
    } else if (c_piece.column > N_COLUMNS - 1) {
        printf("55555\n");
        return 0;
    } else if (c_piece.line > N_LINES) {
        printf("66666\n");
        return 0;
    } else {
        return 1;
    }
}

void addPiece(piece c_piece, char game[N_LINES][N_COLUMNS]) {
    int line, column;
    printf("ENTREI\n");
    if (checkBoundaries(c_piece)) {
        printf("ENTREI 2\n");
        if (c_piece.orientation == 'v') {
            printf("ENTREI 4\n");
            for (line = c_piece.line; line < c_piece.line + c_piece.size; ++line) {
                game[line][c_piece.column] = c_piece.rep;
                printf("AQUI %d line %d column, %c\n", line, c_piece.column, c_piece.rep);
            }
        } else {
            printf("ENTREI 5\n");
            printf("AQUI %d line %d column, %c\n", c_piece.line, c_piece.size, c_piece.rep);
            for (column = c_piece.column; column < c_piece.column + c_piece.size; ++column) {
                game[c_piece.line][column] = c_piece.rep;
                printf("AQUI %d line %d column, %c\n", c_piece.line, column, c_piece.rep);
            }
        }
    }
}

void erasePiece(piece c_piece, char game[N_LINES][N_COLUMNS]) {
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
        t_piece.orientation = 'h';
        if (checkBoundaries(t_piece)) {
            c_piece->orientation = 'h';
        } else if (t_piece.column + t_piece.size > N_COLUMNS) {
            t_piece.column -= (t_piece.size - 1);
            if (checkBoundaries(t_piece)) {
                c_piece->orientation = 'h';
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
            printf("[AQUI1] %d %d", free_line, column);
            game[free_line][column] = c_piece->rep;
        }
    } else {
        for (line = free_line; line > free_line - c_piece->size; --line) {
            printf("[AQUI2] %d %d %d", line, free_line, column);
            game[line][c_piece->column] = c_piece->rep;
        }
    }
}

int freeLine(char orientation, int column, int size, char game[N_LINES][N_COLUMNS]) {
    int line, column_indx;
    if (orientation == 'v') {
        for (line = MAX_LINE; line < N_LINES; ++line) {
            printf("LINE %d COLUMN %d CHAR %c \n", line, column, game[line][column]);
            if (game[line][column] != ' ') {
                return line - 1;
            }
        }
        return line - 1;
    } else {
        for (line = MAX_LINE; line < N_LINES; ++line) {
            for (column_indx = column; column_indx < column + size; ++column_indx) {
                printf("LINE %d COLUMN %d CHAR %c \n", line, column_indx, game[line][column_indx]);
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
        printf("!!!LINE %d %d\n", line, flag);
        flag = 1;
        for (column = 0; column < N_COLUMNS; ++column) {
            if (game[line][column] == ' ') {
                printf("FOUND EMPTY %d %d\n", line, column);
                flag = 0;
                break;
            }
        }
        printf("!!!LINE %d %d\n", line, flag);
        if (flag) {
            *points += 100;
            fillLine(line, line, game);
            cleanScreen(*points, game);
            getchar();
            for (line2 = line; line2 > MAX_LINE; --line2) {
                for (column = 0; column < N_COLUMNS; ++column) {
                    printf("LINE %d COLUMN %d\n", line2, column);
                    game[line2][column] = game[line2 - 1][column];
                }
            }
            --line;
        }
    }
}

int checkLimitReached(char game[N_LINES][N_COLUMNS]) {
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
}

int permitedCommands(char command) {
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
	FILE *fp; 
	char line[7];
	int nseq = 0; 
    piece read_piece;
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
    int indx;
    for (indx = 0; indx < MAX_SEQ; ++indx) {
        printf("Seq %d ->", indx);
        printf("rep %c ", sequences[indx].rep);
        printf("size %d\n", sequences[indx].size);
    }
    
}

void emptyGame(char game[N_LINES][N_COLUMNS]) {
    int line,column;
    for (line = 0; line < N_LINES; ++line) {
        for (column = 0; column < N_COLUMNS; ++column) {
           game[line][column] = ' '; 
        }
    }
}

void fillLine(int bline, int eline, char game[N_LINES][N_COLUMNS]) {
    int line, column;
    for (line = bline; line <= eline; ++line) {
        for (column = 0; column < N_COLUMNS; ++column) {
            game[line][column] = 'X';
        }
    }
}

void cleanActionSpace(char game[][N_COLUMNS]) {
    emptyGame(game);
}
