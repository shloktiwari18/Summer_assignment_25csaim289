#include <stdio.h>

int main()
{
    int number, i, largestFactor = 1;

    printf("Enter a number: ");
    scanf("%d", &number);

    for (i = 2; i <= number; i++)
    {
        while (number % i == 0)
        {
            largestFactor = i;
            number = number / i;
        }
    }

    printf("Largest Prime Factor = %d\n", largestFactor);

    return 0;
}