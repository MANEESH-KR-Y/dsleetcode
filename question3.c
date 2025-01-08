#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** stringMatching(char** words, int wordsSize, int* returnSize) {
    // Allocate memory for the result
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    // Loop through each word to check if it is a substring of any other word
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < wordsSize; j++) {
            if (i != j && strstr(words[j], words[i]) != NULL) {
                // If words[i] is a substring of words[j], add it to the result
                result[*returnSize] = words[i];
                (*returnSize)++;
                break;
            }
        }
    }
    // Return the result
    return result;
}
// Helper function to print the result
void printResult(char** result, int returnSize) {
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("\"%s\"", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");
}
