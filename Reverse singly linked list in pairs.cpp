#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the list
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print a linked list
void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list in pairs
Node* reverseInPairs(Node* head) {
    if (!head || !head->next) {
        return head; // If there are fewer than 2 nodes, no changes needed
    }

    Node* current = head;
    Node* newHead = head->next; // The second node becomes the new head
    Node* nextPair;

    while (current && current->next) {
        nextPair = current->next->next; // Save the start of the next pair
        current->next->next = current; // Reverse the current pair
        if (nextPair && nextPair->next) {
            current->next = nextPair->next; // Connect to the next reversed pair
        } else {
            current->next = nextPair; // Connect to the remaining single node or NULL
        }
        current = nextPair; // Move to the next pair
    }

    return newHead;
}

// Driver code
int main() {
    Node* head = NULL;

    // Creating the linked list
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printf("Original List: ");
    printList(head);

    // Reversing the list in pairs
    head = reverseInPairs(head);

    printf("List after reversing in pairs: ");
    printList(head);

    return 0;
}

