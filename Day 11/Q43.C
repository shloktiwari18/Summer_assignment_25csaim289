#include <stdio.h>

int checkPrime(int n)
{
    int i;

    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (checkPrime(num))
        printf("Prime Number");
    else
        printf("Not Prime Number");

    return 0;
}
