#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// Helper function to merge two sorted linked lists
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    struct ListNode* head = NULL;
    struct ListNode** current = &head;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            *current = l1;
            l1 = l1->next;
        } else {
            *current = l2;
            l2 = l2->next;
        }
        current = &((*current)->next);
    }

    *current = (l1) ? l1 : l2;

    return head;
}

// Function to merge k sorted linked lists
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    if (listsSize == 1) return lists[0];

    while (listsSize > 1) {
        int newSize = (listsSize + 1) / 2; // Pair up lists for merging

        for (int i = 0; i < listsSize / 2; i++) {
            lists[i] = mergeTwoLists(lists[i], lists[listsSize - 1 - i]);
        }

        listsSize = newSize;
    }

    return lists[0];
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
