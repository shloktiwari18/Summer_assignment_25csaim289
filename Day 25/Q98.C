#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "apple";
    char str2[] = "plastic";
    
    char common[100]; // Array to store the common characters we find
    int commonIndex = 0;
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Loop through each character of the first string
    for (int i = 0; i < len1; i++) {
        
        // Loop through each character of the second string to find a match
        for (int j = 0; j < len2; j++) {
            
            // If we find a matching character
            if (str1[i] == str2[j]) {
                
                // We must check if we already added this character to our common array
                int alreadyAdded = 0;
                for (int k = 0; k < commonIndex; k++) {
                    if (str1[i] == common[k]) {
                        alreadyAdded = 1; // Yes, we already saved it before
                        break;
                    }
                }
                
                // If it is a new common character, save it!
                if (alreadyAdded == 0) {
                    common[commonIndex] = str1[i];
                    commonIndex++;
                }
                
                // Break out of the middle loop because we found a match for str1[i]
                break; 
            }
        }
    }
    
    // Don't forget to add the null terminator to make it a proper string
    common[commonIndex] = '\0';
    
    // Print the results
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("Common characters: %s\n", common);
    
    return 0;
}