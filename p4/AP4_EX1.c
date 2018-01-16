#include <stdio.h>
int main(void) {
    int year;
    char sex;
    printf("Inform sex: ");
    scanf("%c", &sex);
    while ((sex != 'f') && (sex != 'F') && (sex != 'm') && 
(sex != 'M')) {
       printf("Error! \n"); 
       printf("Inform o sex: ");
       getchar();
       scanf("%c", &sex);
    }
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Output -> Year = %d e Sex = %c", year, sex);
    return(0);
}
