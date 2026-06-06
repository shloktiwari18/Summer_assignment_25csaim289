#include <stdio.h>

int main()
{
    int position;
    int a = 0, b = 1, fibonacciTerm;

    printf("Enter the Fibonacci position: ");
    scanf("%d", &position);

    if (position == 1)
    {
        printf("Fibonacci term at position %d is %d\n", position, a);
    }
    else if (position == 2)
    {
        printf("Fibonacci term at position %d is %d\n", position, b);
    }
    else
    {
        for (int i = 3; i <= position; i++)
        {
            fibonacciTerm = a + b;
            a = b;
            b = fibonacciTerm;
        }

        printf("Fibonacci term at position %d is %d\n", position, b);
    }

    return 0;
}