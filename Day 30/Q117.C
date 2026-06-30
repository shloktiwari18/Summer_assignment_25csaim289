#include <stdio.h>

int main() {
    int n, i;
    char name[10][20];
    int marks[10];

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter name and marks: ");
        scanf("%s %d", name[i], &marks[i]);
    }

    printf("\nStudent Records\n");
    for(i = 0; i < n; i++) {
        printf("%s - %d\n", name[i], marks[i]);
    }

    return 0;
}