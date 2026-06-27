#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char input[50];
    int secret_number;
    int guess;
    int attempts = 0;

    // Seed the random number generator using the current time
    srand(time(NULL));
    // Generate a random number between 1 and 100
    secret_number = (rand() % 100) + 1;

    printf("====================================\n");
    printf("🎯 Welcome to the Number Guessing Game! 🎯\n");
    printf("====================================\n");
    printf("I'm thinking of a number between 1 and 100.\n\n");

    // Game loop
    while (1) {
        printf("Enter your guess (or type 'exit' to quit): ");
        
        // Read input as a string to allow for 'exit' command and prevent crashing
        if (scanf("%49s", input) != 1) {
            printf("❌ Something went wrong. Try again.\n");
            clear_input_buffer();
            continue;
        }

        // Check if the user wants to quit
        if (strcasecmp(input, "exit") == 0) {
            printf("\n👋 Thanks for playing! The number was %d.\n", secret_number);
            break;
        }

        // Validate that the input is actually a number
        int is_valid_number = 1;
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isdigit(input[i])) {
                is_valid_number = 0;
                break;
            }
        }

        if (!is_valid_number) {
            printf("❌ Invalid input. Please enter a valid whole number.\n\n");
            continue;
        }

        // Convert verified string to integer
        guess = atoi(input);
        attempts++;

        // Check the guess
        if (guess < 1 || guess > 100) {
            printf("⚠️ Please guess a number within the range of 1 to 100.\n\n");
        } else if (guess < secret_number) {
            printf("📉 Too low! Try a higher number.\n\n");
        } else if (guess > secret_number) {
            printf("📈 Too high! Try a lower number.\n\n");
        } else {
            printf("\n🎉 Congratulations! You guessed the number in %d attempts!\n", attempts);
            break;
        }
    }

    return 0;
}