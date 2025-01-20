#include <stdio.h>

void f(int array[], int i, int j) {
    int *pi = array + i;
    int *pj = array + j;
    int t;

    t = *pi;
    *pi = *pj;
    *pj = t;
}

void reorderArray(int array[], int n) {
    int temp[n];
    int index = 0;

    // הוספת כל המספרים החיוביים והאפסים למערך הזמני
    for (int i = 0; i < n; i++) {
        if (array[i] >= 0) {
            temp[index++] = array[i];
        }
    }

    // הוספת כל המספרים השליליים למערך הזמני
    for (int i = 0; i < n; i++) {
        if (array[i] < 0) {
            temp[index++] = array[i];
        }
    }

    // מיון המספרים החיוביים בקבוצות
    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (temp[i] == temp[j] && temp[j] >= 0) {
                f(temp, i + 1, j);
            }
        }
    }

    // העתקת התוצאה חזרה למערך המקורי
    for (int i = 0; i < n; i++) {
        array[i] = temp[i];
    }
}

int main() {
    int array[] = {4, 1, -5, 1, 12, 4, 1, -5, 10, 1};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array before reordering:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    reorderArray(array, n);

    printf("Array after reordering:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
