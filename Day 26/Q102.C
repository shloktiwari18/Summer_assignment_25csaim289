

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char age_input[10];
    char citizen_input[10];
    int age;

    printf("====================================\n");
    printf("     Voting Eligibility System     \n");
    printf("====================================\n");

    // 1. Get and validate age input
    printf("Enter your age: ");
    if (scanf("%9s", age_input) != 1) {
        printf("❌ Error reading input.\n");
        return 1;
    }

    // Check if the age input contains only numbers
    for (int i = 0; age_input[i] != '\0'; i++) {
        if (!isdigit(age_input[i])) {
            printf("❌ Invalid input. Age must be a valid whole number.\n");
            return 1;
        }
    }

    // Convert string to integer
    age = atoi(age_input);

    // Validate realistic age boundaries
    if (age < 0 || age > 120) {
        printf("⚠️ Please enter a realistic age between 0 and 120.\n");
        return 1;
    }

    // 2. Get citizenship input
    printf("Are you a registered citizen? (yes/no): ");
    if (scanf("%9s", citizen_input) != 1) {
        printf("❌ Error reading input.\n");
        return 1;
    }

    printf("\n--- Result ---\n");

    // 3. Evaluate eligibility logic
    // strcasecmp compares strings while ignoring upper/lowercase differences
    if (age >= 18 && strcasecmp(citizen_input, "yes") == 0) {
        printf("🎉 Congratulations! You are ELIGIBLE to vote.\n");
        printf("Make sure you are registered at your local polling station!\n");
    } 
    else if (age < 18 && strcasecmp(citizen_input, "yes") == 0) {
        int years_left = 18 - age;
        printf("❌ You are NOT eligible to vote yet.\n");
        printf("Reason: You must be 18 or older. You can vote in %d years!\n", years_left);
    } 
    else if (age >= 18 && strcasecmp(citizen_input, "yes") != 0) {
        printf("❌ You are NOT eligible to vote.\n");
        printf("Reason: You must be a registered citizen to vote.\n");
    } 
    else {
        printf("❌ You are NOT eligible to vote.\n");
        printf("Reason: You do not meet the age or citizenship requirements.\n");
    }

    return 0;
}
