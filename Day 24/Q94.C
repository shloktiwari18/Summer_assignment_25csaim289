#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Compresses a string using Run-Length Encoding (e.g., "aabcc" -> "a2b1c2").
 * Returns the compressed string if it's shorter; otherwise, returns the original.
 */
char* compressString(const char* original) {
    // 1. Edge Case: If the string is empty or invalid, return it as-is
    if (original == NULL || original[0] == '\0') {
        return (char*)original;
    }

    int originalLen = strlen(original);
    
    // 2. Allocate a safe buffer for compression. 
    // In the absolute worst case (e.g., "abcd"), the compressed version "a1b1c1d1"
    // will be exactly twice the length of the original, plus 1 for the null terminator '\0'.
    char* compressed = (char*)malloc(sizeof(char) * (originalLen * 2 + 1));
    if (compressed == NULL) {
        return NULL; // Out of memory safety check
    }

    int writeIndex = 0;
    int currentRunLength = 1;

    // 3. Loop through the string to compress
    for (int i = 0; i < originalLen; i++) {
        // Look ahead: Is the next character the same as the current one?
        if (i + 1 < originalLen && original[i] == original[i + 1]) {
            currentRunLength++;
        } else {
            // We've hit a new character. Write the character and its count.
            // sprintf returns the number of characters written, which beautifully 
            // advances our writeIndex even if the count is a double-digit number like 12.
            writeIndex += sprintf(&compressed[writeIndex], "%c%d", original[i], currentRunLength);
            
            // Reset the counter for the next sequence
            currentRunLength = 1;
        }
    }

    // 4. Final Comparison: Did we actually save any space?
    // If the compressed version is equal to or longer than the original, discard it.
    if (writeIndex >= originalLen) {
        free(compressed); // Free the memory to prevent leaks
        return (char*)original;
    }

    return compressed;
}

int main() {
    // Test Case 1: Can be compressed successfully
    const char* text1 = "aabcccccaaa";
    char* result1 = compressString(text1);
    printf("Original: %s -> Result: %s\n", text1, result1);
    if (result1 != text1) free(result1); // Only free if new memory was allocated

    // Test Case 2: Compression makes it longer ("a1b1c1d1"), should return original
    const char* text2 = "abcd";
    char* result2 = compressString(text2);
    printf("Original: %s -> Result: %s\n", text2, result2);
    if (result2 != text2) free(result2);

    return 0;
}