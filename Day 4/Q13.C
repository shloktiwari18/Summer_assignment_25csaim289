#include <stdio.h>

int main()
{
    int terms;
    int num1 = 0, num2 = 1, nextNum;

    printf("How many terms do you want in the Fibonacci series? ");
    scanf("%d", &terms);

    printf("Fibonacci Series:\n");

    for (int count = 1; count <= terms; count++)
    {
        printf("%d ", num1);

        nextNum = num1 + num2;
        num1 = num2;
        num2 = nextNum;
    }

    return 0;
}