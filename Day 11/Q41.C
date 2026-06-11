#include <stdio.h>

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int x, y, ans;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    ans = sum(x, y);

    printf("Sum = %d", ans);

    return 0;
}