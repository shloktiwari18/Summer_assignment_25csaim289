#include <stdio.h>

int main()
{
    int num, sum = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0)
    {
        digit = num % 10; // Extract last digit
        sum += digit;     // Add digit to sum
        num /= 10;        // Remove last digit
    }

    printf("Sum of digits = %d\n", sum);

    return 0;
}