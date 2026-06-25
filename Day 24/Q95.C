#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "programming";
    int len = strlen(str);
    
    // We will create a new array to store the unique characters
    // It can be at most the same size as the original string (+1 for '\0')
    char result[100]; 
    int resultIndex = 0;

    // Loop through each character of the original string
    for (int i = 0; i < len; i++) {
        int alreadyExists = 0; // A flag to track if we found a duplicate

        // Check all characters we have added to our result so far
        for (int j = 0; j < resultIndex; j++) {
            if (str[i] == result[j]) {
                alreadyExists = 1; // Found a duplicate!
                break;             // No need to look further, exit this small loop
            }
        }

        // If it's a brand new character, add it to our result array
        if (alreadyExists == 0) {
            result[resultIndex] = str[i];
            resultIndex++; // Move to the next empty spot in result
        }
    }

    // Crucial step: Strings in C must end with a null terminator
    result[resultIndex] = '\0';

    // Print the final clean string
    printf("Original string: %s\n", str);
    printf("After removing duplicates: %s\n", result);

    return 0;
}