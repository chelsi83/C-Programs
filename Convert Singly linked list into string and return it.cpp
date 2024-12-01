#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for singly linked list
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

// Function to append a node to the linked list
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

// Function to convert a linked list to a string
char* linkedListToString(Node* head) {
    if (!head) {
        char* emptyString = (char*)malloc(3 * sizeof(char));
        strcpy(emptyString, "[]");
        return emptyString;
    }

    // Estimate memory needed
    size_t bufferSize = 128; // Start with a reasonable size
    char* result = (char*)malloc(bufferSize * sizeof(char));
    if (!result) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    strcpy(result, "[");
    Node* current = head;
    while (current) {
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "%d", current->data);
        if (strlen(result) + strlen(buffer) + 3 > bufferSize) {
            bufferSize *= 2;
            result = (char*)realloc(result, bufferSize * sizeof(char));
            if (!result) {
                printf("Memory reallocation failed\n");
                exit(1);
            }
        }
        strcat(result, buffer);
        if (current->next) {
            strcat(result, ", ");
        }
        current = current->next;
    }
    strcat(result, "]");
    return result;
}

// Function to free the linked list
void freeLinkedList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function for testing
int main() {
    Node* head = NULL;
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);

    char* result = linkedListToString(head);
    printf("Linked List as String: %s\n", result);

    free(result);
    freeLinkedList(head);

    return 0;
}

