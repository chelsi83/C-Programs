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

// Function to reverse a block of k nodes
struct Node* reverseBlock(struct Node* head, int k) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    int count = 0;

    // Reverse k nodes of the linked list
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Next is now a pointer to the (k+1)th node
    // head is the last node of the reversed block
    if (next != NULL) {
        head->next = reverseBlock(next, k); // Recur for remaining list
    }

    // prev is the new head of the reversed block
    return prev;
}

// Main function
int main() {
    // Creating the linked list
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next = createNode(8);

    printf("Original List: ");
    printList(head);

    int k;
    printf("Enter the block size (k): ");
    scanf("%d", &k);

    // Reverse in blocks of size k
    head = reverseBlock(head, k);

    printf("Reversed List in Blocks of %d: ", k);
    printList(head);

    return 0;
}

