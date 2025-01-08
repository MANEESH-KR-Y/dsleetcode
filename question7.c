#include <stdio.h>
#include <stdlib.h>

// Function to calculate the length of the linked list
int getLength(struct ListNode* head) {
    int length = 0;
    struct ListNode* current = head;
    while (current) {
        length++;
        current = current->next;
    }
    return length;
}

// Function to rotate the list to the right by k places
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) {
        return head; // No rotation needed
    }

    int length = getLength(head);
    k = k % length; // Normalize k to prevent unnecessary rotations

    if (k == 0) {
        return head; // No rotation needed
    }

    // Find the new tail (length - k - 1) and the new head (length - k)
    struct ListNode* current = head;
    for (int i = 1; i < length - k; i++) {
        current = current->next;
    }

    struct ListNode* newHead = current->next;
    current->next = NULL; // Break the list

    // Find the old tail and connect it to the old head
    struct ListNode* tail = newHead;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = head;
    return newHead;
}
// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
// Helper function to print the linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}
