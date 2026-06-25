#include <stdio.h>

int main() {
    // Two arrays that are already sorted
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8, 10};
    
    int size1 = 4;
    int size2 = 5;
    
    // The merged array needs to be big enough to hold both arrays combined
    int size3 = size1 + size2;
    int arr3[100]; // Setting a safe maximum size
    
    int i = 0; // Tracks arr1
    int j = 0; // Tracks arr2
    int k = 0; // Tracks arr3
    
    // Loop as long as BOTH arrays have elements left to compare
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr3[k] = arr1[i]; // Put the smaller number in arr3
            i++;               // Move to next number in arr1
        } else {
            arr3[k] = arr2[j]; // Put the smaller number in arr3
            j++;               // Move to next number in arr2
        }
        k++; // Move to the next empty slot in arr3
    }
    
    // If we finished arr2, copy the leftover numbers from arr1
    while (i < size1) {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    
    // If we finished arr1, copy the leftover numbers from arr2
    while (j < size2) {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    
    // Print the final merged array
    printf("Merged sorted array: ");
    for (int m = 0; m < size3; m++) {
        printf("%d ", arr3[m]);
    }
    printf("\n");
    
    return 0;
}