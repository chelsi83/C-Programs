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

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to remove nodes with values greater than x
struct Node* removeGreaterThanX(struct Node* head, int x) {
    struct Node* current = head;
    struct Node* prev = NULL;

    // Traverse the list
    while (current != NULL) {
        // Check if the current node's value is greater than x
        if (current->data > x) {
            if (prev == NULL) {
                // Remove the head node
                head = current->next;
                free(current);
                current = head;
            } else {
                // Remove the current node
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            // Move to the next node
            prev = current;
            current = current->next;
        }
    }
    return head;
}

// Main function
int main() {
    // Creating the linked list
    struct Node* head =

