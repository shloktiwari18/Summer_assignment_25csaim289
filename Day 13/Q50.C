#include <stdio.h>

int main()
{
    int arr[10], i;
    int total = 0;
    float avg;

    printf("Enter 10 elements:\n");

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
        total += arr[i];
    }

    avg = total / 10.0;

    printf("Sum = %d\n", total);
    printf("Average = %.2f\n", avg);

    return 0;
}