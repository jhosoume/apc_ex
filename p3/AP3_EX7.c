#include<stdio.h>

int main(void) {
    int team_size = 3, teams = 2;
    int team, athlete, code, age, max_code = 1;
    float weight, height, max_height = 0.0, mean_weight, team_weight, mean_age, team_age;
    for (team = 1; team <= teams; ++team) {
        printf("Enter the code, height, weight, age of the %d athletes from team %d ", team_size, team);
        for (athlete = 0; athlete < team_size; ++athlete) {
            scanf("%d%f%f%d", &code, &height, &weight, &age);
            if (height > max_height) {
                max_code = code;
                max_height = height;
            }
            team_weight += weight;
            team_age += age;
        }
        mean_weight += team_weight;
        mean_age = team_age;
        printf("\nThe team %d has mean weight of %2.2f and mean age of %2.2f.\n", team, team_weight/team_size, team_age/team_size);
    }
    printf("\nThe mean weight is %2.2f and the mean age is %2.2f", mean_weight/(teams * team_size), mean_age/(teams * team_size));
    printf("\nThe athlete %d is the tallest with %2.2f.", max_code, max_height);
    return 0;
}
