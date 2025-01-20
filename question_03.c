#include <stdio.h>

// Function to swap the values of two indices in an array
void f(int array[], int i, int j) {
    int *pi = array + i; // Pointer to the element at index i
    int *pj = array + j; // Pointer to the element at index j
    int t;

    t = *pi;   // Store the value at index i in a temporary variable
    *pi = *pj; // Assign the value at index j to index i
    *pj = t;   // Assign the stored value (original i) to index j
}

// Function to reorder the array so that identical numbers are grouped together
void reorderArray(int array[], int n) {
    int temp[n]; // Temporary array to store rearranged values
    int index = 0;

    // Copy all numbers (positive and negative) to the temporary array
    for (int i = 0; i < n; i++) {
        temp[index++] = array[i];
    }

    // Group identical numbers (both positive and negative) together
    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            // Check if two numbers are identical
            if (temp[i] == temp[j]) {
                f(temp, i + 1, j); // Swap using the f() function to group them
            }
        }
    }

    // Copy the reordered temp array back to the original array
    for (int i = 0; i < n; i++) {
        array[i] = temp[i];
    }
}

// Main function to test the reorderArray function
int main() {
    int array[] = {4,1,-5,1,12,4,1,-5,10,1}; // Input array
    int n = sizeof(array) / sizeof(array[0]); // Calculate the size of the array

    // Print the array before reordering
    printf("Array before reordering:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Call the reorderArray function to reorder the array
    reorderArray(array, n);

    // Print the array after reordering
    printf("Array after reordering:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0; // Exit the program
}
