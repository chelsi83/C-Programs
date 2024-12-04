#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
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

// Function to swap every two adjacent nodes
struct Node* swapAdjacentNodes(struct Node* head) {
    // Edge case: if the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Initialize pointers for swapping
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* newHead = head->next; // The second node will become the new head

    // Traverse the list in pairs
    while (current != NULL && current->next != NULL) {
        struct Node* next = current->next;

        // Swap the current pair of nodes
        current->next = next->next;
        next->next = current;

        // Update the previous node's next to point to the new first node
        if (prev != NULL) {
            prev->next = next;
        }

        // Move the pointers for the next pair
        prev = current;
        current = current->next;
    }

    return newHead;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test the program
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);

    printf("Original list:\n");
    printList(head);

    head = swapAdjacentNodes(head);

    printf("Modified list after swapping adjacent nodes:\n");
    printList(head);

    return 0;
}


