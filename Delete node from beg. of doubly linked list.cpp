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

// Function to delete a node from the beginning of the doubly linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("The list is already empty.\n");
        return NULL;
    }

    struct Node* temp = head;

    // Update the head to the next node
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    printf("Node with data %d deleted from the beginning.\n", temp->data);
    free(temp); // Free the memory of the deleted node

    return head;
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
        printf("1. Insert at beginning\n");
        printf("2. Delete from beginning\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                struct Node* newNode = createNode(data);
                if (head != NULL) {
                    newNode->next = head;
                    head->prev = newNode;
                }
                head = newNode;
                printf("Node inserted at the beginning.\n");
                break;

            case2:
                head = deleteFromBeginning(head);
                break;

            case3:
                displayDoublyLinkedList(head);
                break;

            case4:
                printf("Exiting...\n");
                return 0;

        default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

