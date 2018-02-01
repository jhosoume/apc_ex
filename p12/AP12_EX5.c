#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};

struct employee {
    char name[20];
    char position[20];
    char department[20];
    float salary;
    struct date admission;
};

int getNum() {
    int num;
    printf("Enter the number of employess that will be on table ");
    scanf("%d", &num);
    getchar();
    return num;
}

void readEmployees(int num, struct employee employee_list[num]) {
    int indx;
    for (indx = 0; indx < num; ++indx) {
        printf("Employee Name: ");
        scanf("%s", employee_list[indx].name);
        getchar();
        printf("Position: ");
        scanf("%s", employee_list[indx].position);
        getchar();
        printf("Department: ");
        scanf("%s", employee_list[indx].department);
        getchar();
        printf("Salary: ");
        scanf("%f", &employee_list[indx].salary);
        getchar();
        printf("Date of admission (dd/mm/yyyy): ");
        scanf("%d %d %d", &employee_list[indx].admission.day, &employee_list[indx].admission.month, &employee_list[indx].admission.year);
        getchar();
        printf("\n");
    }
}

float meanSalary(int num, struct employee employees[num]) {
    int indx;
    float sum = 0;
    for (indx = 0; indx < num; ++indx) {
        sum += employees[indx].salary;
    }
    return sum/num;
}

int salaryBigger(int num, struct employee employees[num], struct employee higher_salary[num]) {
    int indx, indx2 = 0;
    float mean = meanSalary(num, employees);
    for (indx = 0; indx < num; ++indx) {
        if (employees[indx].salary > mean) {
            higher_salary[indx2] = employees[indx];
            ++indx2;
        }
    }
    return indx2;
}

void printEmployee(struct employee emp) {
    printf("Name: %s\n", emp.name);
    printf("Position: %s\n", emp.position);
    printf("Department: %s\n", emp.department);
    printf("Salary: %f\n", emp.salary);
    printf("Date of admission: %d/%d/%d\n", emp.admission.day, emp.admission.month, emp.admission.year);
    printf("\n");

}

void higherSalaries(int size, struct employee employee_list[]) {
    int indx;
    for (indx = 0; indx < size; ++indx) {
        printEmployee(employee_list[indx]);
    }
}

int main() {
    int num_employees, high_salary_size;
    num_employees = getNum();
    struct employee employees_list[num_employees];
    struct employee employees_high_salary[num_employees];
    readEmployees(num_employees, employees_list);
    high_salary_size = salaryBigger(num_employees, employees_list, employees_high_salary);
    higherSalaries(high_salary_size, employees_high_salary);   
}
