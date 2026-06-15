#include <stdio.h>

int main()
{
    int arr[10], i, last;

    printf("Enter 10 elements:\n");

    for(i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    last = arr[9];

    for(i = 9; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = last;

    printf("Array after right rotation:\n");

    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}