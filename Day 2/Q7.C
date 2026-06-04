#include <stdio.h>

int main()
{
    int num, digit, product = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0)
    {
        digit = num % 10; // Extract last digit
        product *= digit; // Multiply digit with product
        num /= 10;        // Remove last digit
    }

    printf("Product of digits = %d\n", product);

    return 0;
}