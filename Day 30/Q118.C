#include <stdio.h>

struct Book {
    int id;
    char name[20];
    int issued;
};

int main() {
    struct Book b[5];
    int n, i, id, ch;

    printf("Enter number of books: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter ID and Name: ");
        scanf("%d %s", &b[i].id, b[i].name);
        b[i].issued = 0;
    }

    printf("1.Display 2.Issue\nEnter choice: ");
    scanf("%d", &ch);

    if(ch == 1) {
        for(i = 0; i < n; i++)
            printf("%d %s %s\n", b[i].id, b[i].name,
                   b[i].issued ? "Issued" : "Available");
    }
    else if(ch == 2) {
        printf("Enter Book ID: ");
        scanf("%d", &id);

        for(i = 0; i < n; i++) {
            if(b[i].id == id)
                b[i].issued = 1;
        }
        printf("Book Issued!");
    }

    return 0;
}