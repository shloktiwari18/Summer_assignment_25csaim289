#include <stdio.h>

int main() {
    int firstArray[] = {1, 2, 3, 4};
    int secondArray[] = {5, 6, 7, 8};

    int size1 = sizeof(firstArray) / sizeof(firstArray[0]);
    int size2 = sizeof(secondArray) / sizeof(secondArray[0]);

    int mergedArray[size1 + size2];

    // Copy elements of first array
    for (int i = 0; i < size1; i++) {
        mergedArray[i] = firstArray[i];
    }

    // Copy elements of second array
    for (int i = 0; i < size2; i++) {
        mergedArray[size1 + i] = secondArray[i];
    }

    printf("Merged Array: ");

    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedArray[i]);
    }

    return 0;
}