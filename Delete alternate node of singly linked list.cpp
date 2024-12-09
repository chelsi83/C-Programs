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

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to delete alternate nodes of a linked list
void deleteAlternateNodes(Node* head) {
    if (!head) return; // If the list is empty

    Node* current = head;
    Node* temp;

    while (current && current->next) {
        temp = current->next;  // Node to be deleted
        current->next = temp->next;  // Link current node to the node after temp
        free(temp);  // Free memory of the deleted node
        current = current->next;  // Move to the next valid node
    }
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

    // Deleting alternate nodes
    deleteAlternateNodes(head);

    printf("List after deleting alternate nodes: ");
    printList(head);

    return 0;
}

