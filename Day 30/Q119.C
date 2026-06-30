#include <stdio.h>

struct Employee {
    int id;
    char name[20];
    int salary;
};

int main() {
    struct Employee e[10];
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter ID, Name, Salary: ");
        scanf("%d %s %d", &e[i].id, e[i].name, &e[i].salary);
    }

    printf("\nEmployee Records\n");
    for(i = 0; i < n; i++) {
        printf("%d %s %d\n", e[i].id, e[i].name, e[i].salary);
    }

    return 0;
}