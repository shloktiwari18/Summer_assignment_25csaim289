#include <stdio.h>
#include <string.h>

int main() {
    // A list of 5 names. Each name can be up to 19 characters long (+1 for '\0')
    char names[5][20] = {
        "Rahul",
        "Amit",
        "Zayan",
        "Binod",
        "Deepak"
    };
    
    int totalNames = 5;
    char temp[20]; // A temporary variable used for swapping names

    // Bubble Sort loops
    for (int i = 0; i < totalNames - 1; i++) {
        for (int j = 0; j < totalNames - 1 - i; j++) {
            
            // strcmp returns a number greater than 0 if names[j] comes AFTER names[j+1]
            if (strcmp(names[j], names[j+1]) > 0) {
                
                // Swap the two names using strcpy (string copy)
                strcpy(temp, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], temp);
                
            }
        }
    }

    // Print the sorted list
    printf("Names in alphabetical order:\n");
    for (int i = 0; i < totalNames; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    return 0;
}