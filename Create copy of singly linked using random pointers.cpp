#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* random;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;
}

// Function to print a linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("Data: %d, Random: %d\n", temp->data, temp->random ? temp->random->data : -1);
        temp = temp->next;
    }
    printf("\n");
}

// Function to clone a linked list with random pointers
struct Node* cloneList(struct Node* head) {
    if (!head) return NULL;

    // Step 1: Interweave original and cloned nodes
    struct Node* current = head;
    while (current) {
        struct Node* newNode = createNode(current->data);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }

    // Step 2: Assign random pointers to the cloned nodes
    current = head;
    while (current) {
        if (current->random) {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }

    // Step 3: Separate the cloned list from the original list
    struct Node* clonedHead = head->next;
    struct Node* clonedCurrent = clonedHead;
    current = head;

    while (current) {
        current->next = current->next->next;
        if (clonedCurrent->next) {
            clonedCurrent->next = clonedCurrent->next->next;
        }
        current = current->next;
        clonedCurrent = clonedCurrent->next;
    }

    return clonedHead;
}

// Main function to test the program
int main() {
    // Create a test linked list
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Setting up random pointers
    head->random = head->next->next;         // 1 -> 3
    head->next->random = head;               // 2 -> 1
    head->next->next->random = head->next;   // 3 -> 2
    head->next->next->next->random = head;   // 4 -> 1

    printf("Original list:\n");
    printList(head);

    struct Node* clonedHead = cloneList(head);

    printf("Cloned list:\n");
    printList(clonedHead);

    return 0;
}

