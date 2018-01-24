#include <stdio.h>

void readTemp(float temps[]) {
    int indx;
    printf("Give the mean temperature of each month ");
    for (indx = 0; indx < 12; ++indx) {
        scanf("%f", &temps[indx]);
    }
}

float max(float seq[], int size, int *max_month) {
    int indx, max_value = seq[0];
    for (indx = 1; indx < size; ++indx) {
        if (max_value < seq[indx]) {
            max_value = seq[indx];
            *max_month = indx + 1;
        }
    }
    return max_value;
}

float min(float seq[], int size, int *min_month) {
    int indx, min_value = seq[0];
    for (indx = 1; indx < size; ++indx) {
        if (min_value > seq[indx]) {
            min_value = seq[indx];
            *min_month = indx + 1;
        }
    }
    return min_value;
}

int main() {
    float temps[12];
    float max_temp, min_temp;
    int max_month, min_month;

    readTemp(temps);
    max_temp = max(temps, 12, &max_month);
    min_temp = min(temps, 12, &min_month);
    
    printf("The month of maximum temperature %3.2f is %d\n", max_temp, max_month);
    printf("The month of minimum temperature %3.2f is %d\n", min_temp, min_month);

    return 0;
}
