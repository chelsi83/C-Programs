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

// Function to delete a node from the middle of the doubly linked list
struct Node* deleteFromMiddle(struct Node* head, int position) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }

    struct Node* temp = head;

    // Traverse to the node at the specified position
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL) {
        printf("Position out of range. Node not deleted.\n");
        return head;
    }

    // Update the pointers of adjacent nodes
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else { // If deleting the head node
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    printf("Deleted node with data: %d\n", temp->data);
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
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a node at the end\n");
        printf("2. Delete from middle (by position)\n");
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
                printf("Enter the position to delete the node: ");
                scanf("%d", &position);
                head = deleteFromMiddle(head, position);
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

