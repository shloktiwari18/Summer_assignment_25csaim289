#include <stdio.h>
#include <string.h>

int main() {
    char str[50];
    int ch;

    printf("Enter String: ");
    scanf("%s", str);

    printf("1.Length\n2.Reverse\nEnter choice: ");
    scanf("%d", &ch);

    if(ch == 1)
        printf("Length = %lu", strlen(str));
    else if(ch == 2) {
        strrev(str);
        printf("Reverse = %s", str);
    }
    else
        printf("Invalid Choice");

    return 0;
}