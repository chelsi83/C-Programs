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

// Function to add a node at the end of the list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to partition the linked list
struct Node* partitionList(struct Node* head, int x) {
    struct Node* lessHead = NULL, *lessTail = NULL;
    struct Node* greaterHead = NULL, *greaterTail = NULL;

    struct Node* current = head;

    // Partition the nodes into two lists
    while (current != NULL) {
        if (current->data < x) {
            if (lessHead == NULL) {
                lessHead = lessTail = current;
            } else {
                lessTail->next = current;
                lessTail = lessTail->next;
            }
        } else {
            if (greaterHead == NULL) {
                greaterHead = greaterTail = current;
            } else {
                greaterTail->next = current;
                greaterTail = greaterTail->next;
            }
        }
        current = current->next;
    }

    // Combine the two lists
    if (lessTail != NULL) {
        lessTail->next = greaterHead;
    }

    // Ensure the end of the greater list points to NULL
    if (greaterTail != NULL) {
        greaterTail->next = NULL;
    }

    // Return the new head (lessHead if it exists, otherwise greaterHead)
    return (lessHead != NULL) ? lessHead : greaterHead;
}

int main() {
    struct Node* head = NULL;

    // Create a linked list
    appendNode(&head, 3);
    appendNode(&head, 5);
    appendNode(&head, 8);
    appendNode(&head, 5);
    appendNode(&head, 10);
    appendNode(&head, 2);
    appendNode(&head, 1);

    printf("Original list: ");
    printList(head);

    int x;
    printf("Enter the partition value: ");
    scanf("%d", &x);

    head = partitionList(head, x);

    printf("Partitioned list: ");
    printList(head);

    return 0;
}

