#include <stdio.h>

int main() {
    int numbers[] = {1, 2, 2, 3, 4, 2, 5, 3, 3, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int maxFrequency = 0;
    int mostFrequentElement = numbers[0];

    for (int i = 0; i < size; i++) {
        int count = 1;

        // Count occurrences of numbers[i]
        for (int j = i + 1; j < size; j++) {
            if (numbers[i] == numbers[j]) {
                count++;
            }
        }

        // Update maximum frequency and element
        if (count > maxFrequency) {
            maxFrequency = count;
            mostFrequentElement = numbers[i];
        }
    }

    printf("Most frequent element: %d\n", mostFrequentElement);
    printf("Frequency: %d\n", maxFrequency);

    return 0;
}