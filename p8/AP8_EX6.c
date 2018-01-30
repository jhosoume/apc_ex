#include <stdio.h>
#include <string.h>

void readPhrase(char phrase[], int *begin, int *length) {
    printf("Enter phrase ");  
    scanf("%[^\n]s%*c ", phrase);
    printf("Inform index to begin the removing ");
    scanf("%d", begin);
    printf("How much chars will be taken? ");
    scanf("%d", length);
}

void removeChars(char s1[], char s2[], int begin, int length) {
    int size_s1 = strlen(s1), indx, indx2 = 0;
    for (indx = 0; indx < size_s1; ++indx) {
        if (indx < begin || indx >= begin + length) {
            s2[indx2] = s1[indx];
            ++indx2;
        }
    }
    s2[indx2] = '\0';
}

int main() {
    int size = 21, begin, length;
    char s1[size], s2[size];
    readPhrase(s1, &begin, &length);
    removeChars(s1, s2, begin, length);
    printf("Output: %s", s2);
    return 0;
}
