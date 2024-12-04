#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
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

// Function to interleave two linked lists
struct Node* interleaveLists(struct Node* head1, struct Node* head2) {
    // If one of the lists is empty, return the other
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* dummy = createNode(0); // Dummy node to simplify logic
    struct Node* current = dummy;      // Pointer to build the new list

    while (head1 != NULL && head2 != NULL) {
        // Append a node from the first list
        current->next = head1;
        head1 = head1->next;
        current = current->next;

        // Append a node from the second list
        current->next = head2;
        head2 = head2->next;
        current = current->next;
    }

    // Append remaining nodes from the longer list
    if (head1 != NULL) {
        current->next = head1;
    } else if (head2 != NULL) {
        current->next = head2;
    }

    struct Node* interleavedHead = dummy->next;
    free(dummy); // Free the dummy node
    return interleavedHead;
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test the program
int main() {
    // Create first list: 1 -> 2 -> 3
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);

    // Create second list: 10 -> 20 -> 30 -> 40
    struct Node* head2 = createNode(10);
    head2->next = createNode(20);
    head2->next->next = createNode(30);
    head2->next->next->next = createNode(40);

    printf("List 1:\n");
    printList(head1);

    printf("List 2:\n");
    printList(head2);

    // Interleave the two lists
    struct Node* interleavedHead = interleaveLists(head1, head2);

    printf("Interleaved list:\n");
    printList(interleavedHead);

    return 0;
}

