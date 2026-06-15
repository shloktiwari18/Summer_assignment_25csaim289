#include <stdio.h>

int main()
{
    int arr[10], i, j = 0, temp;

    printf("Enter 10 elements:\n");

    for(i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < 10; i++)
    {
        if(arr[i] != 0)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }

    printf("Array after moving zeroes to the end:\n");

    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}