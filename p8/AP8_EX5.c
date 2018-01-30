#include <stdio.h>
#include <string.h>

void readPhrase(char phrase[], int *begin, int *length) {
    printf("Enter phrase to be cropped ");  
    scanf("%[^\n]s%*c ", phrase);
    printf("Inform index to begin the crop ");
    scanf("%d", begin);
    printf("How much chars will be taken? ");
    scanf("%d", length);
}

void crop(char s1[], char s2[], int begin, int length) {
    int size_s1 = strlen(s1), indx, indx2;
    for (indx = begin, indx2 = 0; indx < size_s1 && indx < begin + length; ++indx, ++indx2) {
        s2[indx2] = s1[indx];
    }
    s2[++indx2] = '\0';
}

int main() {
    int size = 21, begin, length;
    char s1[size], s2[size];
    readPhrase(s1, &begin, &length);
    crop(s1, s2, begin, length);
    printf("Output: %s", s2);
    return 0;
}
