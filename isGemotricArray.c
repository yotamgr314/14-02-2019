#include <stdio.h>

// Recursive function to check if the array is a geometric sequence with q > 1
int isGeometricArray(int arr[], int n) {
    // Base case: If there are fewer than 2 elements left, the sequence is valid
    if (n <= 2) {
        return 1;
    }

    // Calculate the ratio q between the first two elements
    double q = (double)arr[1] / arr[0];

    // Check if the ratio q <= 1 or if the ratio between consecutive elements is not consistent
    if (q <= 1 || (double)arr[1] / arr[0] != (double)arr[2] / arr[1]) {
        return 0;
    }

    // Recursive call with the next part of the array
    return isGeometricArray(arr + 1, n - 1);
}

int main() {
    int arr1[] = {2, 4, 8, 16, 32, 64}; // Example of a valid geometric sequence
    int arr2[] = {3, 9, 36, 108};       // Example of a invalid geometric sequence
    int arr3[] = {2, 4, 7, 16};         // Example of an invalid geometric sequence

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    printf("Array 1 is geometric: %d\n", isGeometricArray(arr1, n1)); // Expected output: 1
    printf("Array 2 is geometric: %d\n", isGeometricArray(arr2, n2)); // Expected output: 0
    printf("Array 3 is geometric: %d\n", isGeometricArray(arr3, n3)); // Expected output: 0

    return 0;
}
