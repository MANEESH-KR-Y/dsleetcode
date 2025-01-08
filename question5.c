#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to detect a cycle in a linked list
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    // Use two pointers, slow and fast
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move slow pointer by 1 step
        fast = fast->next->next;    // Move fast pointer by 2 steps

        if (slow == fast) {
            return true; // A cycle is detected
        }
    }

    return false; // No cycle found
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
