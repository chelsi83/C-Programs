#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to find the maximum value in the doubly linked list
int findMaxValue(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return -1;  // Return -1 if the list is empty
    }

    int max = head->data;
    struct Node* temp = head;
    
    // Traverse the list to find the maximum value
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

// Function to display the doubly linked list
void displayDoublyLinkedList(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a node at the end\n");
        printf("2. Find the maximum value\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                struct Node* newNode = createNode(data);

                if (head == NULL) {
                    head = newNode; // If the list is empty, the new node becomes the head
                } else {
                    struct Node* temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next; // Traverse to the last node
                    }
                    temp->next = newNode;
                    newNode->prev = temp;
                }
                break;

            case 2:
                {
                    int max = findMaxValue(head);
                    if (max != -1) {
                        printf("The maximum value in the list is: %d\n", max);
                    }
                }
                break;

            case 3:
                displayDoublyLinkedList(head);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

