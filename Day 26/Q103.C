#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to clear the input buffer to prevent infinite loops on typos
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int choice;
    double balance = 1000.00; // Starting account balance
    double amount;

    printf("====================================\n");
    printf("    🏦 Welcome to the Citizen ATM 🏦    \n");
    printf("====================================\n");

    while (1) {
        // Display Menu
        printf("\nMain Menu:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Please select an option (1-4): ");

        // Validate choice input
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input. Please enter a number between 1 and 4.\n");
            clear_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                // Check Balance
                printf("\n💵 Your current balance is: $%.2f\n", balance);
                break;

            case 2:
                // Deposit Money
                printf("\nEnter amount to deposit: $");
                if (scanf("%g", &amount) != 1 || amount <= 0) {
                    printf("❌ Invalid amount. Transaction canceled.\n");
                    clear_buffer();
                } else {
                    balance += amount;
                    printf("✅ Successfully deposited $%.2f. New balance: $%.2f\n", amount, balance);
                }
                break;

            case 3:
                // Withdraw Money
                printf("\nEnter amount to withdraw: $");
                if (scanf("%g", &amount) != 1 || amount <= 0) {
                    printf("❌ Invalid amount. Transaction canceled.\n");
                    clear_buffer();
                } else if (amount > balance) {
                    printf("❌ Insufficient funds! You cannot withdraw more than $%.2f\n", balance);
                } else {
                    balance -= amount;
                    printf("✅ Successfully withdrew $%.2f. Remaining balance: $%.2f\n", amount, balance);
                }
                break;

            case 4:
                // Exit
                printf("\nThank you for using our ATM. Goodbye! 👋\n");
                return 0;

            default:
                printf("❌ Invalid choice. Please select a valid option from the menu.\n");
        }
    }

    return 0;
}