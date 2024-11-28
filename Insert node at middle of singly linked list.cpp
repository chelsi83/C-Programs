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

// Function to insert a node at a specific position in the list
struct Node* insertInMiddle(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);

    // If the position is 1 or the list is empty, insert at the beginning
    if (position == 1 || head == NULL) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    struct Node* temp = head;
    int i = 1;

    // Traverse to the node just before the desired position
    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }

    // If the position is beyond the current length of the list, insert at the end
    if (temp == NULL) {
        printf("Position is beyond the current list length. Inserting at the end.\n");
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Function to display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
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
    int choice, data, position;

    printf("Singly Linked List - Insert in Middle\n");
    while (1) {
        printf("\n1. Insert a node in the middle\n");
        printf("2. Display the list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert the node: ");
                scanf("%d", &position);
                head = insertInMiddle(head, data, position);
                printf("Node inserted successfully.\n");
                break;

            case 2:
                printf("The current list is: ");
                displayList(head);
                break;

            case 3:
                freeList(head);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

