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

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to interleave two linked lists
struct Node* interleaveLists(struct Node* head1, struct Node* head2) {
    struct Node* current1 = head1;
    struct Node* current2 = head2;
    struct Node* next1;
    struct Node* next2;

    while (current1 != NULL && current2 != NULL) {
        next1 = current1->next; // Save the next node of list 1
        next2 = current2->next; // Save the next node of list 2

        current1->next = current2; // Link the node from list 2 after current1
        if (next1 == NULL) break; // If the next node in list 1 is NULL, stop

        current2->next = next1; // Link the node from list 1 after current2
        current1 = next1;       // Move to the next node in list 1
        current2 = next2;       // Move to the next node in list 2
    }

    return head1;
}

// Main function
int main() {
    // Creating the first linked list
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);

    // Creating the second linked list
    struct Node* head2 = createNode(4);
    head2->next = createNode(5);
    head2->next->next = createNode(6);
    head2->next->next->next = createNode(7);

    printf("List 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    // Interleaving the lists
    struct Node* interleavedHead = interleaveLists(head1, head2);

    printf("Interleaved List: ");
    printList(interleavedHead);

    return 0;
}

