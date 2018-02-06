#include "engine.h"

void start() {
	char game[N_LINES][N_COLUMNS];
    int n_pieces;
	piece sequences[MAX_SEQ]; 
    n_pieces = readSequences("sequences.txt", sequences);
    showScreen();
    startMessage();
    emptyGame(N_LINES, N_COLUMNS, game);
    /*printSequences(MAX_SEQ, sequences);*/
    /*addPiece(sequences[0], N_LINES, N_COLUMNS, game);*/
    /*cleanScreen(0, N_LINES, N_COLUMNS, game);*/
    gameLoop(n_pieces, sequences, N_LINES, N_COLUMNS, game);
}


void checkMatrix(int nlines, int ncolumns, char game[nlines][ncolumns]) {
    int line, column;
    for (line = 0; line < nlines; ++line) {
        for (column = 0; column < ncolumns; ++column) {
            printf("Line: %d Columns: %d Value: %c\n", line, column, game[line][column]);
        }
    }
}


int checkBoundaries(piece c_piece, int nlines, int ncolumns) {
    printf("ENTREI 3\n");
    if (c_piece.orientation == 'h' && c_piece.column + c_piece.size > ncolumns) {
        printf("11111\n");
        return 0;
    } else if (c_piece.orientation == 'v' && c_piece.line + c_piece.size > nlines) {
        printf("22222\n");
        return 0;
    } else if (c_piece.line < 0) {
        printf("33333\n");
        return 0;
    } else if ( c_piece.column < 0) {
        printf("44444\n");
        return 0;
    } else if (c_piece.column > ncolumns - 1) {
        printf("55555\n");
        return 0;
    } else if (c_piece.line > nlines) {
        printf("66666\n");
        return 0;
    } else {
        return 1;
    }
}

void addPiece(piece c_piece, int nlines, int ncolumns, char game[nlines][ncolumns]) {
    int line, column;
    printf("ENTREI\n");
    if (checkBoundaries(c_piece, nlines, ncolumns)) {
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

void erasePiece(piece c_piece, int nlines, int ncolumns, char game[nlines][ncolumns]) {
    int line, column;
    if (checkBoundaries(c_piece, nlines, ncolumns)) {
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

int gameLoop(int num_pieces, piece sequences[MAX_SEQ], int nlines, int ncolumns, char game[N_LINES][N_COLUMNS]) {
    int times = 0, count;
    int points = 0;
    char command;
    addPiece(sequences[times], nlines, ncolumns, game);
    while (times < num_pieces && checkLimitReached()) {
        cleanScreen(points, nlines, ncolumns, game);
        command = getCommand(); 
        count = defineAction(command, &sequences[times], game);
        printf("TIMES %d", times);
        times += count;
    }
    return 1;
}

void endGame(int stats) {
    switch (stats) {
        case 1:
            break;
        case 0:
            break;
        default:
            break;
    }
}

void moveRight(piece *c_piece, char game[N_LINES][N_COLUMNS]) {
    piece t_piece = *c_piece;
    erasePiece(*c_piece, N_LINES, N_COLUMNS, game);
    t_piece.column += 1;
    if (checkBoundaries(t_piece, N_LINES, N_COLUMNS)) {
        c_piece->column +=1;
    }
    addPiece(*c_piece, N_LINES, N_COLUMNS, game);
}

void moveLeft(piece *c_piece, char game[N_LINES][N_COLUMNS]) {
    piece t_piece = *c_piece;
    erasePiece(*c_piece, N_LINES, N_COLUMNS, game);
    t_piece.column -= 1;
    if (checkBoundaries(t_piece, N_LINES, N_COLUMNS)) {
        c_piece->column -= 1;
    }
    addPiece(*c_piece, N_LINES, N_COLUMNS, game);
}

void rotate(piece *c_piece, char game[N_LINES][N_COLUMNS]) {
    piece t_piece = *c_piece;
    erasePiece(*c_piece, N_LINES, N_COLUMNS, game);
    if (c_piece->orientation == 'h') {
        t_piece.orientation = 'v';
        if (checkBoundaries(t_piece, N_LINES, N_COLUMNS)) {
            c_piece->orientation = 'v';
        }
    } else {
        t_piece.orientation = 'h';
        if (checkBoundaries(t_piece, N_LINES, N_COLUMNS)) {
            c_piece->orientation = 'h';
        } else if (t_piece.column + t_piece.size > N_COLUMNS) {
            t_piece.column -= (t_piece.size - 1);
            if (checkBoundaries(t_piece, N_LINES, N_COLUMNS)) {
                c_piece->orientation = 'h';
                c_piece->column -= (c_piece->size - 1);
            }
        }
    }
    addPiece(*c_piece, N_LINES, N_COLUMNS, game);
}

void fall(piece *c_piece, char game[N_LINES][N_COLUMNS], int points) {
    int free_line = freeLine(c_piece->orientation, c_piece->column, c_piece->size, game);
    erasePiece(*c_piece, N_LINES, N_COLUMNS, game);


}

int freeLine(char orientation, int column, int size, char game[N_LINES][N_COLUMNS]) {
    int line, column_indx;
    if (orientation == 'v') {
        for (line = 0; line > N_LINES; ++line) {
            if (game[line][column] != ' ')
                return line - 1;
        }
        return line;
    } else {
        for (line = 0; line > N_LINES; ++line) {
            for (column_indx = column; column_indx < column + size; ++column) {
                if (game[line][column_indx] != ' ')
                    return line - 1;
            }
        }
        return line;
    }
}

void checkCompletedLines() {
}

int checkLimitReached() {
    return 1;
}

void startMessage() {
    printf("Tecle <enter> para iniciar o jogo");
    getchar();
}

void loseMessage() {
    printf("*** YOU LOSE!!! Tecle <enter> para sair");
    getchar();
}

void winMessage(int points) {
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

int defineAction(char command, piece *c_piece, char game[N_LINES][N_COLUMNS]) {
    switch (command) {
        case 'r':
        case 'R':
            printf("Rotate\n");
            rotate(c_piece, game);
            printf("Rotate\n");
            return 0;
        case 'd':
        case 'D':
            printf("Go right\n");
            moveRight(c_piece, game);
            return 0;
        case 'e':
        case 'E':
            printf("Go left\n");
            moveLeft(c_piece, game);
            return 0;
        case 'c':
        case 'C':
            printf("Go fall\n");
            return 1;
        case 'q':
        case 'Q':
            printf("Go quit\n");
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
        sequences[nseq].column = 9;
        sequences[nseq].size = strlen(line);
        ++nseq;
	}
	fclose(fp); 
    return nseq;
}

void printSequences(int num_seq, piece sequences[num_seq]) {
    int indx;
    for (indx = 0; indx < num_seq; ++indx) {
        printf("Seq %d ->", indx);
        printf("rep %c ", sequences[indx].rep);
        printf("size %d\n", sequences[indx].size);
    }
    
}

void emptyGame(int nlines, int ncolumns, char game[nlines][ncolumns]) {
    int line,column;
    for (line = 0; line < nlines; ++line) {
        for (column = 0; column < ncolumns; ++column) {
           game[line][column] = ' '; 
        }
    }
}

void fillGame(int nlines, int ncolumns, char game[nlines][ncolumns]) {
    int line, column;
    for (line = 0; line < nlines; ++line) {
        for (column = 0; column < ncolumns; ++column) {
            game[line][column] = 'X';
        }
    }
}

void cleanActionSpace(char game[][20]) {
    emptyGame(6, 20, game);
}
