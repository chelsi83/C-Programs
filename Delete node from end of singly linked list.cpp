#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to delete the last node of the list
struct Node* deleteLastNode(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    if (head->next == NULL) {
        // If there's only one node, delete it
        printf("Deleted node with data: %d\n", head->data);
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    // Traverse to the second-last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // Unlink the last node
    prev->next = NULL;
    printf("Deleted node with data: %d\n", temp->data);
    free(temp);

    return head;
}

// Function to display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the allocated memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    printf("Singly Linked List - Delete Last Node\n");
    while (1) {
        printf("\n1. Insert a node at the end\n");
        printf("2. Delete the last node\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printf("Node inserted successfully.\n");
                break;

            case 2:
                head = deleteLastNode(head);
                break;

            case 3:
                printf("The current list is: ");
                displayList(head);
                break;

            case 4:
                freeList(head);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

