#include <stdio.h>

int main() {
    int numbers[] = {1, 2, 3, 2, 4, 1, 5, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Array after removing duplicates: ");

    for (int i = 0; i < size; i++) {
        int isDuplicate = 0;

        // Check if the current element appeared before
        for (int j = 0; j < i; j++) {
            if (numbers[i] == numbers[j]) {
                isDuplicate = 1;
                break;
            }
        }

        // Print only unique elements
        if (!isDuplicate) {
            printf("%d ", numbers[i]);
        }
    }

    return 0;
}