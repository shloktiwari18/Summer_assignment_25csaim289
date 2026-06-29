#include <stdio.h>

struct Ticket {
    int ticketNo;
    char name[20];
    int seatNo;
};

int main() {
    struct Ticket t;

    printf("Enter Ticket No: ");
    scanf("%d", &t.ticketNo);

    printf("Enter Passenger Name: ");
    scanf("%s", t.name);

    printf("Enter Seat No: ");
    scanf("%d", &t.seatNo);

    printf("\nTicket Details\n");
    printf("Ticket No: %d\n", t.ticketNo);
    printf("Passenger: %s\n", t.name);
    printf("Seat No: %d\n", t.seatNo);

    return 0;
}