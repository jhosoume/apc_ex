#include<stdio.h>

float ideal_weight(char sex, float height) {
    switch (sex) {
        case 'f':
        case 'F':
            return (62.1 * height - 44.7);
        case 'm':
        case 'M':
            return (72.7 * height - 58);
        default:
            return (72.7 * height - 58);
    }
}

int main(void) {
    int num_people, id;
    char sex;
    float height;
    
    printf("Enter number of people that will be evaluated ");
    scanf("%d", &num_people);

    for (id = 1; id <= num_people; ++id) {
        do {
            printf("For person %d, give height and sex ", id);
            scanf("%f %c", &height, &sex);
        } while (sex != 'f' && sex != 'F' && sex != 'm' && sex != 'M');
        printf("The ideal weight is %3.2f\n", ideal_weight(sex, height));
    }

    return 0;
}
