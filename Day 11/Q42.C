

#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int n1, n2, m;

    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);

    m = max(n1, n2);

    printf("Maximum = %d", m);

    return 0;
}