#include <stdio.h>

struct Contact {
    char name[20];
    char phone[15];
};

int main() {
    struct Contact c;

    printf("Enter Name: ");
    scanf("%s", c.name);

    printf("Enter Phone Number: ");
    scanf("%s", c.phone);

    printf("\nContact Details\n");
    printf("Name: %s\n", c.name);
    printf("Phone: %s\n", c.phone);

    return 0;
}