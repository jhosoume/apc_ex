#include <stdio.h>
#include <string.h>

void readString(char phrase[], int num) {
    printf("Enter %d-nt list of words ", num);
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

void printEquals(char *phrase1, char *phrase2, int size) {
    char words[2][size + 1][size + 1];
    int num_words1, num_words2, indx, indx2;
    num_words1 = separateWords(phrase1, size + 1, words[0]);
    num_words2 = separateWords(phrase2, size + 1, words[1]);
    printf("Equal words are: \n");
    for (indx = 0; indx < num_words1; ++indx) {
        for (indx2 = 0; indx2 < num_words2; ++indx2) {
            if (compare(words[0][indx], words[1][indx2]) == 1)
                printf("%s ", words[0][indx]);
        }
    }
}

int main() {
    int size = 21;
    char p1[size], p2[size];
    readString(p1, 1);
    readString(p2, 2);
    printEquals(p1, p2, size);
    return 0;
}
