#include <stdio.h>

int main() {
    int firstArray[] = {1, 2, 3, 4, 5};
    int secondArray[] = {3, 4, 5, 6, 7};

    int size1 = sizeof(firstArray) / sizeof(firstArray[0]);
    int size2 = sizeof(secondArray) / sizeof(secondArray[0]);

    printf("Common Elements: ");

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (firstArray[i] == secondArray[j]) {
                printf("%d ", firstArray[i]);
                break; // Move to next element after finding a match
            }
        }
    }

    return 0;
}