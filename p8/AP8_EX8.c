#include <stdio.h>
#include <string.h>

void readString(char phrase[]) {
    printf("Enter list of words ");
    scanf("%[^\n]s%*c", phrase);
    getchar();
}

int separateWords(char phrase[], int length, char words[][length]) {
    int size = strlen(phrase), num_words = 0, indx_phrase = 0, indx_word = 0;
    char letter = phrase[indx_phrase];
    while (indx_phrase < size) {
        letter = phrase[indx_phrase];
        while (letter == ' ') {
            indx_phrase++;
            letter = phrase[indx_phrase];
        }
        while (letter != ' ') {
            words[num_words][indx_word] = letter;
            indx_word++; indx_phrase++;
            letter = phrase[indx_phrase];
        }
        /* Remember to close the string */
        words[num_words][indx_word] = '\0';
        num_words++;
        indx_phrase++;
        indx_word = 0;
    }
    return num_words;
}

void invert(char s1[]) {
    int indx, size = strlen(s1);
    char aux;
    for (indx = 0; indx < size/2; ++indx) {
        aux = s1[size - 1 - indx];
        s1[size - 1 - indx] = s1[indx];
        s1[indx] = aux;
    }
}

void printSubs(char phrase[], int size) {
    char words[size][size];
    int num_words, indx;
    num_words = separateWords(phrase, size, words);
    for (indx = 0; indx < num_words; ++indx) {
        invert(words[indx]);
        printf("%s ", words[indx]);
    }
}

int main() {
    int size = 21;
    char phrase[size];
    readString(phrase);
    printSubs(phrase, size);
    return 0;
}
