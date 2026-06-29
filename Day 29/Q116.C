#include <stdio.h>

struct Item {
    int id, qty;
    char name[20];
};

int main() {
    struct Item i;

    printf("Enter Item ID: ");
    scanf("%d", &i.id);

    printf("Enter Item Name: ");
    scanf("%s", i.name);

    printf("Enter Quantity: ");
    scanf("%d", &i.qty);

    printf("\nInventory Details\n");
    printf("Item ID: %d\n", i.id);
    printf("Item Name: %s\n", i.name);
    printf("Quantity: %d\n", i.qty);

    return 0;
}