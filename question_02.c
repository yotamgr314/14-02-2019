// QUESTION 02

#include <stdio.h>

int panagram(char *s) {
    int alphabet[26] = {0}; // מערך לבדיקה של כל אותיות האלפבית
    int index;

    for (int i = 0; s[i] != '\0'; i++) {
        // בדיקה אם התו הוא אות גדולה
        if (s[i] >= 'A' && s[i] <= 'Z') {
            index = s[i] - 'A'; // מחשב את האינדקס של האות באלפבית
            alphabet[index] = 1; // מסמן שאות זו הופיעה
        }
        // בדיקה אם התו הוא אות קטנה
        else if (s[i] >= 'a' && s[i] <= 'z') {
            index = s[i] - 'a'; // מחשב את האינדקס של האות באלפבית
            alphabet[index] = 1; // מסמן שאות זו הופיעה
        }
    }

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] == 0) { // אם יש אות אחת שלא הופיעה
            return 0; // המחרוזת אינה פאנגרמה
        }
    }

    return 1; // המחרוזת היא פאנגרמה
}

int main() {
    char test1[] = "The quick brown fox jumps over the lazy dog";
    char test2[] = "Pack my box with five dozen liquor jugs";
    char test3[] = "Lovely C Programming";

    printf("Test 1: %d\n", panagram(test1)); // אמור להחזיר 1
    printf("Test 2: %d\n", panagram(test2)); // אמור להחזיר 1
    printf("Test 3: %d\n", panagram(test3)); // אמור להחזיר 0

    return 0;
}
