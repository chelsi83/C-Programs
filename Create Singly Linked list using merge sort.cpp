#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to split the linked list into two halves
void splitList(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    struct Node* slow = source;
    struct Node* fast = source->next;

    // Use slow and fast pointers to find the middle
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Function to merge two sorted linked lists
struct Node* sortedMerge(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;

    struct Node* result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }

    return result;
}

// Function to implement merge sort on a linked list
void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef

