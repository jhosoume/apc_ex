#include <stdio.h>

struct profession {
    int code;
    char name[20];
};

int getNum() {
    int num;
    printf("Enter the number of professions that will be on table ");
    scanf("%d", &num);
    getchar();
    return num;
}

int getCode() {
    int num;
    printf("Enter the code of the profession to be found ");
    scanf("%d", &num);
    getchar();
    return num;
}

void readProfs(int num, struct profession profession_list[num]) {
    int indx;
    for (indx = 0; indx < num; ++indx) {
        printf("Profession code: ");
        scanf("%d", &profession_list[indx].code);
        getchar();
        printf("Profession name: ");
        scanf("%s", profession_list[indx].name);
        getchar();
        printf("\n");
    }
}

int findProf(int code, int num, struct profession profession_list[num]) {
    int indx;
    for (indx = 0; indx < num; ++indx) {
        if (profession_list[indx].code == code)
            return indx;
    }
    return -1;
}

void searchResult(int indx, struct profession prof_list[]) {
    if (indx == -1)
        printf("Profession not found");
    else 
        printf("Profession is %s", prof_list[indx].name);
}

void printProf(struct profession prof) {
    printf("Profession: %s\n", prof.name);
    printf("Profession code: %d\n", prof.code);
}

int main() {
    int num_profs, code, indx;
    num_profs = getNum();
    struct profession professions_list[num_profs];
    readProfs(num_profs, professions_list);
    code = getCode();
    indx = findProf(code, num_profs,  professions_list);
    searchResult(indx, professions_list);
}
