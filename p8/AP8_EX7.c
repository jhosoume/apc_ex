#include <stdio.h>
#include <string.h>

void readString(char phrase[], char old[], char new[]) {
    printf("Enter list of words ");
    scanf("%[^\n]s%*c", phrase);
    getchar();
    printf("Enter word to be substituted ");
    scanf("%[^\n]s%*c", old);
    getchar();
    printf("Enter new word ");
    scanf("%[^\n]s%*c", new);
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

int compare(char *s1, char *s2) {
    int size_s1 = strlen(s1), size_s2 = strlen(s2), indx = 0;
    if (size_s1 != size_s2) {
        return 0;
    } else {
        while (indx < size_s1) {
            if (s1[indx] != s2[indx]) {
                return 0;
            }
            ++indx;
        }
    }
    return 1;
    
}

void printSubs(char phrase[], char old[], char new[], int size) {
    char words[size][size];
    int num_words, indx;
    num_words = separateWords(phrase, size, words);
    for (indx = 0; indx < num_words; ++indx) {
        if (compare(words[indx], old) == 1) {
            printf("%s ", new);
        } else {
            printf("%s ", words[indx]);
        }
    }
}

int main() {
    int size = 21, size_words = 11;
    char phrase[size], old[size_words], new[size_words];
    readString(phrase, old, new);
    printSubs(phrase, old, new, size);
    return 0;
}
