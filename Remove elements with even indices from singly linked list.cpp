#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the singly linked list
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

// Function to append a node to the list
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

// Function to remove elements with even indices
void removeEvenIndices(Node** head) {
    if (*head == NULL) return;

    Node* curr = *head;
    Node* prev = NULL;
    int index = 0;

    while (curr != NULL) {
        if (index % 2 == 0) { // Even index
            Node* temp = curr;
            if (prev == NULL) { // Removing the head node
                *head = curr->next;
                curr = *head;
            } else {
                prev->next = curr->next;
                curr = curr->next;
            }
            free(temp);
        } else { // Odd index
            prev = curr;
            curr = curr->next;
        }
        index++;
    }
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the program
int main() {
    Node* head = NULL;

    // Add elements to the list
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);
    appendNode(&head, 6);

    printf("Original list:\n");
    printList(head);

    // Remove elements with even indices
    removeEvenIndices(&head);

    printf("List after removing elements with even indices:\n");
    printList(head);

    return 0;
}

