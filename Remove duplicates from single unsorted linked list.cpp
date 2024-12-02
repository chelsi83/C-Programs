#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SIZE 1000  // Assuming elements are in the range 0-999

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

// Function to remove duplicates from the linked list
void removeDuplicates(struct Node* head) {
    if (!head) return;

    bool hashTable[HASH_SIZE] = { false }; // Hash table to track visited elements
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current) {
        if (hashTable[current->data]) {
            // Duplicate found, remove the current node
            prev->next = current->next;
            free(current);
        } else {
            // Mark the value as seen
            hashTable[current->data] = true;
            prev = current;
        }
        current = prev->next;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test the program
int main() {
    struct Node* head = createNode(10);
    head->next = createNode(12);
    head->next->next = createNode(11);
    head->next->next->next = createNode(11);
    head->next->next->next->next = createNode(12);
    head->next->next->next->next->next = createNode(10);

    printf("Original list: ");
    printList(head);

    removeDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}

