#include <stdio.h>

int main() {
    int numbers[] = {1, 2, 3, 5};
    int n = 5;  // Numbers should be from 1 to 5
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int totalSum = n * (n + 1) / 2;
    int arraySum = 0;

    // Calculate the sum of elements present in the array
    for (int i = 0; i < size; i++) {
        arraySum += numbers[i];
    }

    int missingNumber = totalSum - arraySum;

    printf("The missing number is: %d\n", missingNumber);

    return 0;
}