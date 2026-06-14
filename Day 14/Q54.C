#include <stdio.h>

int main()
{
    int arr[10], i, element;
    int freq = 0;

    printf("Enter 10 elements:\n");

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &element);

    for (i = 0; i < 10; i++)
    {
        if (arr[i] == element)
        {
            freq++;
        }
    }

    printf("Frequency of %d is %d\n", element, freq);

    return 0;
}