#include <stdio.h>

int main()
{
    int number, originalNumber, digit;
    int sum = 0, factorial, i;

    printf("Enter a number: ");
    scanf("%d", &number);

    originalNumber = number;

    while (number > 0)
    {
        digit = number % 10;

        factorial = 1;
        for (i = 1; i <= digit; i++)
        {
            factorial *= i;
        }

        sum += factorial;
        number /= 10;
    }

    if (sum == originalNumber)
        printf("%d is a Strong Number.\n", originalNumber);
    else
        printf("%d is not a Strong Number.\n", originalNumber);

    return 0;
}