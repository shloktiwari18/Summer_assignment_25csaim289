#include <stdio.h>

int main() {
    int ch;
    float a, b;

    printf("Enter two numbers: ");
    scanf("%f%f", &a, &b);

    printf("1.Add\n2.Sub\n3.Mul\n4.Div\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    switch(ch) {
        case 1: printf("Result = %.2f", a + b); break;
        case 2: printf("Result = %.2f", a - b); break;
        case 3: printf("Result = %.2f", a * b); break;
        case 4: printf("Result = %.2f", a / b); break;
        default: printf("Invalid Choice");
    }

    return 0;
}