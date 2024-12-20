#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to reverse the linked list in pairs
Node* reverseInPairs(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; // Base case: 0 or 1 node
    }

    Node* newHead = head->next; // New head is the second node
    Node* remaining = newHead->next; // Remaining list after the pair

    newHead->next = head; // Reverse the pair
    head->next = reverseInPairs(remaining); // Recursively reverse the rest

    return newHead;
}

// Function to print a linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test the program
int main() {
    Node* head = NULL;

    // Add elements to the linked list
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);
    appendNode(&head, 6);

    printf("Original list:\n");
    printList(head);

    // Reverse the list in pairs
    head = reverseInPairs(head);

    printf("List after reversing in pairs:\n");
    printList(head);

    return 0;
}

