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

// Function to find the length of a linked list
int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find the intersection point of two linked lists
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Align both lists to the same starting point
    while (len1 > len2) {
        head1 = head1->next;
        len1--;
    }
    while (len2 > len1) {
        head2 = head2->next;
        len2--;
    }

    // Traverse both lists and find the intersection
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL; // No intersection
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Create two linked lists
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);

    struct Node* head2 = createNode(4);
    head2->next = createNode(5);

    // Create intersection
    head2->next->next = head1->next->next;

    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    // Find intersection
    struct Node* intersection = findIntersection(head1, head2);
    if (intersection) {
        printf("Intersection point data: %d\n", intersection->data);
    } else {
        printf("No intersection.\n");
    }

    return 0;
}

