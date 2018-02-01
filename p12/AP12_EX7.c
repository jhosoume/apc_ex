#include <stdio.h>
#include <string.h>

struct date {
    int day;
    int month;
    int year;
};

struct contact {
    char name[20];
    char address[20];
    float phone;
    struct date birthday;
};

int getNum() {
    int num;
    printf("Enter the number of employess that will be on table ");
    scanf("%d", &num);
    getchar();
    return num;
}

void readContacts(int num, struct contact contact_list[num]) {
    int indx;
    for (indx = 0; indx < num; ++indx) {
        printf("Name: ");
        scanf("%s", contact_list[indx].name);
        getchar();
        printf("Address: ");
        scanf("%s", contact_list[indx].address);
        getchar();
        printf("Phone: ");
        scanf("%f", &contact_list[indx].phone);
        getchar();
        printf("Birthday (dd/mm/yyyy): ");
        scanf("%d %d %d", &contact_list[indx].birthday.day, &contact_list[indx].birthday.month, &contact_list[indx].birthday.year);
        getchar();
        printf("\n");
    }
}

int birthdayMonth(int month, int num, struct contact contacts[num], struct contact birth_month[num]) {
    int indx, indx2 = 0;
    for (indx = 0; indx < num; ++indx) {
        if (contacts[indx].birthday.month == month) {
            birth_month[indx2] = contacts[indx];
            ++indx2;
        }
    }
    return indx2;
}

void printContacts(struct contact cnt) {
    printf("Name: %s\n", cnt.name);
    printf("Address: %s\n", cnt.address);
    printf("Phone: %f\n", cnt.phone);
    printf("Birthday: %d/%d/%d\n", cnt.birthday.day, cnt.birthday.month, cnt.birthday.year);
    printf("\n");

}

void printList(int size, struct contact contact_list[]) {
    int indx;
    for (indx = 0; indx < size; ++indx) {
        printContacts(contact_list[indx]);
    }
}

void swapContact(struct contact *c1, struct contact *c2) {
    struct contact aux;
    aux = *c1;
    *c1 = *c2;
    *c2 = aux;
}

void orderList(int size, struct contact contact_list[size]) {
    int indx, flag;
    do {
        flag = 0;
        for (indx = 0; indx < size - 1; ++indx) {
            if(strcmp(contact_list[indx].name, contact_list[indx + 1].name) > 0) {
                swapContact(&contact_list[indx], &contact_list[indx + 1]);
                flag = 1;
            }
        }
    } while (flag);
}

int main() {
    int num_contacts;
    num_contacts = getNum();
    struct contact contacts_list[num_contacts];
    readContacts(num_contacts, contacts_list);
    orderList(num_contacts, contacts_list);
    printList(num_contacts, contacts_list);   
}
