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

// Function to create a doubly linked list
struct Node* createDoublyLinkedList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int data, i;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode; // First node becomes the head
        } else {
            temp->next = newNode;
            newNode->prev = temp;
        }
        temp = newNode; // Update the temporary pointer
    }
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
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The number of nodes must be greater than 0.\n");
        return 0;
    }

    struct Node* head = createDoublyLinkedList(n);
    displayDoublyLinkedList(head);

    return 0;
}

