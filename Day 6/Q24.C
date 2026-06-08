#include <stdio.h>

int main()
{
    int x, n, r = 1, i;

    printf("Enter base and power: ");
    scanf("%d%d", &x, &n);

    for (i = 0; i < n; i++)
    {
        r = r * x;
    }

    printf("Result = %d", r);

    return 0;
}