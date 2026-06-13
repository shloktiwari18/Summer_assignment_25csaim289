#include <stdio.h>

int main()
{
    int num[10], i;
    int max, min;

    printf("Enter 10 numbers:\n");

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
    }

    // Assume first element is largest and smallest
    max = num[0];
    min = num[0];

    // Find largest and smallest element
    for (i = 1; i < 10; i++)
    {
        if (num[i] > max)
            max = num[i];

        if (num[i] < min)
            min = num[i];
    }

    printf("Largest number = %d\n", max);
    printf("Smallest number = %d\n", min);

    return 0;
}
