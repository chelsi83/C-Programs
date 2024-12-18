#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
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

// Function to insert a node at the end of the list
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

// Function to reorder the linked list
void reorderEvenOdd(Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    Node* evenHead = NULL, *evenTail = NULL; // To hold even-numbered nodes
    Node* oddHead = NULL, *oddTail = NULL;   // To hold odd-numbered nodes
    Node* curr = *head;

    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            // Add to even list
            if (evenHead == NULL) {
                evenHead = evenTail = curr;
            } else {
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
        } else {
            // Add to odd list
            if (oddHead == NULL) {
                oddHead = oddTail = curr;
            } else {
                oddTail->next = curr;
                oddTail = oddTail->next;
            }
        }
        curr = curr->next;
    }

    // Connect even and odd lists
    if (evenTail != NULL) evenTail->next = oddHead;
    if (oddTail != NULL) oddTail->next = NULL;

    // Update the head to point to the even list
    *head = evenHead != NULL ? evenHead : oddHead;
}

// Function to print a linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test the program
int main() {
    Node* head = NULL;

    // Add elements to the linked list
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);
    appendNode(&head, 6);

    printf("Original list:\n");
    printList(head);

    // Reorder the linked list
    reorderEvenOdd(&head);

    printf("Reordered list (even nodes ahead of odd nodes):\n");
    printList(head);

    return 0;
}

