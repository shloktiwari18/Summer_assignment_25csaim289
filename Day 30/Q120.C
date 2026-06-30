#include <stdio.h>

void input(char name[][20], int marks[], int n) {
    for(int i = 0; i < n; i++)
        scanf("%s %d", name[i], &marks[i]);
}

void display(char name[][20], int marks[], int n) {
    for(int i = 0; i < n; i++)
        printf("%s %d\n", name[i], marks[i]);
}

int main() {
    char name[10][20];
    int marks[10], n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter name and marks:\n");
    input(name, marks, n);

    printf("\nStudent Records:\n");
    display(name, marks, n);

    return 0;
}