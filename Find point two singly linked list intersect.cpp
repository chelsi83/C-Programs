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

// Function to find the length of a linked list
int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find the intersection point
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move the pointer of the longer list by the difference in lengths
    if (len1 > len2) {
        for (int i = 0; i < diff; i++) {
            head1 = head1->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            head2 = head2->next;
        }
    }

    // Traverse both lists together until an intersection is found
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1; // Intersection point
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL; // No intersection
}

// Helper function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Create two intersecting linked lists
    struct Node* newNode;

    // List 1: 1 -> 2 -> 3
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);

    // List 2: 10 -> 20
    struct Node* head2 = createNode(10);
    head2->next = createNode(20);

    // Create intersection: 30 -> 40 -> NULL
    newNode = createNode(30);
    head1->next->next->next = newNode;
    head2->next->next = newNode;

    newNode->next = createNode(40);

    printf("List 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    // Find the intersection point
    struct Node* intersectionPoint = findIntersection(head1, head2);
    if (intersectionPoint != NULL) {
        printf("The intersection point is: %d\n", intersectionPoint->data);
    } else {
        printf("The lists do not intersect.\n");
    }

    return 0;
}

