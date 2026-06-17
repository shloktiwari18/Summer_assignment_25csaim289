#include <stdio.h>

int main() {
    int firstArray[] = {1, 2, 3, 4, 5};
    int secondArray[] = {4, 5, 6, 7, 8};

    int size1 = sizeof(firstArray) / sizeof(firstArray[0]);
    int size2 = sizeof(secondArray) / sizeof(secondArray[0]);

    printf("Union of Arrays: ");

    // Print all elements of first array
    for (int i = 0; i < size1; i++) {
        printf("%d ", firstArray[i]);
    }

    // Print only unique elements from second array
    for (int i = 0; i < size2; i++) {
        int isPresent = 0;

        for (int j = 0; j < size1; j++) {
            if (secondArray[i] == firstArray[j]) {
                isPresent = 1;
                break;
            }
        }

        if (!isPresent) {
            printf("%d ", secondArray[i]);
        }
    }

    return 0;
}