#include <stdio.h>

int main()
{
    int n, d = 0, r, p = 1;

    printf("Enter binary number: ");
    scanf("%d", &n);

    while (n > 0)
    {
        r = n % 10;
        d = d + r * p;
        p = p * 2;
        n = n / 10;
    }

    printf("Decimal number = %d", d);

    return 0;
}