#include <stdio.h>

int rev = 0;

int reverse(int n)
{
    if (n == 0)
        return 0;

    rev = rev * 10 + n % 10;
    reverse(n / 10);

    return rev;
}

int main()
{
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    printf("Reverse = %d", reverse(n));

    return 0;
}