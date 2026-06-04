#include <stdio.h>

int main()
{
    int num, reverse = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0)
    {
        digit = num % 10; // Extract last digit
        reverse = reverse * 10 + digit;
        num = num / 10; // Remove last digit
    }

    printf("Reversed number = %d\n", reverse);

    return 0;
}