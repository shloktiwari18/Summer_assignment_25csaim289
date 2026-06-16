#include <stdio.h>

int main() {
    int numbers[] = {2, 7, 11, 15, 3, 6};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int targetSum = 9;

    int pairFound = 0;

    // Check every possible pair
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (numbers[i] + numbers[j] == targetSum) {
                printf("Pair found: (%d, %d)\n", numbers[i], numbers[j]);
                pairFound = 1;
            }
        }
    }

    if (!pairFound) {
        printf("No pair found with sum %d\n", targetSum);
    }

    return 0;
}