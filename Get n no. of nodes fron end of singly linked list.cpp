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

// Function to find the nth node from the end of the linked list
struct Node* getNthFromEnd(struct Node* head, int n) {
    struct Node* fast = head;
    struct Node* slow = head;

    // Move the fast pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (fast == NULL) {
            printf("The list has fewer than %d nodes.\n", n);
            return NULL;
        }
        fast = fast->next;
    }

    // Move both pointers until the fast pointer reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

int main() {
    struct Node* head = NULL;

    // Create a linked list
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);
    appendNode(&head, 50);

    printf("Linked list: ");
    printList(head);

    int n;
    printf("Enter the position from the end: ");
    scanf("%d", &n);

    struct Node* result = getNthFromEnd(head, n);
    if (result) {
        printf("The %d-th node from the end is: %d\n", n, result->data);
    }

    return 0;
}

