#include <stdio.h>

int main() {
    int a[5], i, ch;

    printf("Enter 5 elements: ");
    for(i = 0; i < 5; i++)
        scanf("%d", &a[i]);

    printf("1.Display\n2.Sum\nEnter choice: ");
    scanf("%d", &ch);

    if(ch == 1) {
        for(i = 0; i < 5; i++)
            printf("%d ", a[i]);
    }
    else if(ch == 2) {
        int sum = 0;
        for(i = 0; i < 5; i++)
            sum += a[i];
        printf("Sum = %d", sum);
    }
    else
        printf("Invalid Choice");

    return 0;
}