#include <stdio.h>

int main()
{
    int num[10], i, key, found = 0;

    printf("Enter 10 numbers:\n");

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &key);

    for (i = 0; i < 10; i++)
    {
        if (num[i] == key)
        {
            found = 1;
            printf("Number found at position %d\n", i + 1);
            break;
        }
    }

    if (found == 0)
    {
        printf("Number not found\n");
    }

    return 0;
}