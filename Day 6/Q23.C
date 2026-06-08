#include <stdio.h>

int main()
{
    int n, c = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    while (n > 0)
    {
        if (n % 2 == 1)
            c++;

        n = n / 2;
    }

    printf("Set bits = %d", c);

    return 0;
}