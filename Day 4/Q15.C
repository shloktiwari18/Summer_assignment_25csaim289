#include <stdio.h>

int main()
{
    int number, originalNumber, digit;
    int sum = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    originalNumber = number;

    while (number > 0)
    {
        digit = number % 10;
        sum = sum + (digit * digit * digit);
        number = number / 10;
    }

    if (sum == originalNumber)
        printf("%d is an Armstrong number.\n", originalNumber);
    else
        printf("%d is not an Armstrong number.\n", originalNumber);

    return 0;
}