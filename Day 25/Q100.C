#include <stdio.h>
#include <string.h>

int main() {
    // A list of 5 words. Each word can be up to 19 characters long
    char words[5][20] = {
        "elephant",
        "cat",
        "banana",
        "dog",
        "it"
    };
    
    int totalWords = 5;
    char temp[20]; // A temporary variable used for swapping words

    // Bubble Sort loops
    for (int i = 0; i < totalWords - 1; i++) {
        for (int j = 0; j < totalWords - 1 - i; j++) {
            
            // Check if the length of the current word is greater than the next word
            if (strlen(words[j]) > strlen(words[j+1])) {
                
                // Swap the two words using strcpy
                strcpy(temp, words[j]);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1], temp);
                
            }
        }
    }

    // Print the sorted list of words
    printf("Words sorted by length (shortest to longest):\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s (Length: %d)\n", words[i], (int)strlen(words[i]));
    }

    return 0;
}