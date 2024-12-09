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

// Function to split a singly linked list into two halves
void splitList(Node* head, Node** firstHalf, Node** secondHalf) {
    if (head == NULL) {
        *firstHalf = NULL;
        *secondHalf = NULL;
        return;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    // Use slow and fast pointers to find the middle of the list
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list into two halves
    *firstHalf = head;
    if (prev) {
        prev->next = NULL;  // End the first half
    }
    *secondHalf = slow;  // Start of the second half
}

// Driver code
int main() {
    Node* head = NULL;
    Node* firstHalf = NULL;
    Node* secondHalf = NULL;

    // Creating the linked list
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printf("Original List: ");
    printList(head);

    // Splitting the list
    splitList(head, &firstHalf, &secondHalf);

    printf("First Half: ");
    printList(firstHalf);

    printf("Second Half: ");
    printList(secondHalf);

    return 0;
}

