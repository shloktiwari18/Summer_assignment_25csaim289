#include <stdio.h>

int main()
{
    int num[10], i;
    int even = 0, odd = 0;

    printf("Enter 10 numbers:\n");

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);

        if (num[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("Number of Even elements = %d\n", even);
    printf("Number of Odd elements = %d\n", odd);

    return 0;
}