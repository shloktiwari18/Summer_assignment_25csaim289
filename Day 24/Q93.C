#include <stdio.h>
#define ASCII_SIZE 256

char findFirstUniqueChar(const char* str) {
    // Edge case: If the string is empty or NULL, return a placeholder
    if (str == NULL || str[0] == '\0') {
        return '$';
    }

    // Initialize an array to keep track of how many times each character appears
    int charCounts[ASCII_SIZE] = {0};

    // Step 1: Scan the string and count character frequencies
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char currentChar = str[i];
        charCounts[currentChar]++;
    }

    // Step 2: Scan the string a second time to find the first character with a count of 1
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char currentChar = str[i];
        if (charCounts[currentChar] == 1) {
            return str[i]; // Found it! Return immediately.
        }
    }

    // If we looped through the whole string and found no unique characters
    return '$'; 
}

int main() {
    char word[] = "swiss";
    char result = findFirstUniqueChar(word);

    if (result != '$') {
        printf("The first non-repeating character in \"%s\" is '%c'.\n", word, result);
    } else {
        printf("All characters repeat in \"%s\".\n", word);
    }

    return 0;
}