#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* stack;
    int top;
    int capacity;
} Stack;
// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->stack = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}
// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}
// Function to push an element onto the stack
void push(Stack* stack, char item) {
    stack->stack[++stack->top] = item;
}
// Function to pop an element from the stack    
char pop(Stack* stack) {
    return stack->stack[stack->top--];
}
// Function to get the top element of the stack
char peek(Stack* stack) {
    return stack->stack[stack->top];
}
// Function to free the stack memory
void freeStack(Stack* stack) {
    free(stack->stack);
    free(stack);
}
bool isValid(char* s) {
     int len = strlen(s);
    Stack* stack = createStack(len);
    for (int i = 0; i < len; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            // Push opening brackets onto the stack
            push(stack, ch);
        } else {
            // Check if the stack is empty (unmatched closing bracket)
            if (isEmpty(stack)) {
                freeStack(stack);
                return false;
            }
            // Check for matching pairs
            char top = peek(stack);
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                pop(stack); // Pop the matched pair
            } else {
                freeStack(stack);
                return false; // Mismatched pair
            }
        }
    }
    // Check if the stack is empty (all brackets matched)
    bool result = isEmpty(stack);
    freeStack(stack);
    return result;
}
