#include <stdio.h>

int main() {
    int a[10][10], rows, cols;
    int i, j, sum;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nColumn-wise Sum:\n");

    for(j = 0; j < cols; j++) {
        sum = 0;
        for(i = 0; i < rows; i++) {
            sum += a[i][j];
        }
        printf("Sum of Column %d = %d\n", j + 1, sum);
    }

    return 0;
}