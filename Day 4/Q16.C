#include <stdio.h>

int main()
{
    int start, end, number, originalNumber, digit, sum;

    printf("Enter the starting and ending numbers: ");
    scanf("%d %d", &start, &end);

    printf("Armstrong numbers between %d and %d are:\n", start, end);

    for (number = start; number <= end; number++)
    {
        originalNumber = number;
        sum = 0;

        while (originalNumber > 0)
        {
            digit = originalNumber % 10;
            sum += digit * digit * digit;
            originalNumber /= 10;
        }

        if (sum == number)
        {
            printf("%d ", number);
        }
    }

    return 0;
}