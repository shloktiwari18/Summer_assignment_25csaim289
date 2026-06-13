#include <stdio.h>

int main()
{
    int numbers[10];
    int i;

    // Taking input from the user
    printf("Enter 10 numbers:\n");
    for (i = 0; i < 10; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Displaying the entered numbers
    printf("\nThe numbers you entered are:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}