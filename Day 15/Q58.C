#include <stdio.h>

int main()
{
    int arr[10], i, first;

    printf("Enter 10 elements:\n");

    for(i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    first = arr[0];

    for(i = 0; i < 9; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[9] = first;

    printf("Array after left rotation:\n");

    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}