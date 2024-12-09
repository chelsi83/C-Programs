#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of a list
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print a linked list
void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to merge alternate nodes of two linked lists
void mergeAlternate(Node* list1, Node* list2) {
    Node* temp1 = list1;
    Node* temp2 = list2;
    Node* next1, *next2;

    // Traverse both lists and alternate nodes
    while (temp1 && temp2) {
        next1 = temp1->next;
        next2 = temp2->next;

        temp1->next = temp2;
        if (next1 == NULL) break; // End of list1
        temp2->next = next1;

        temp1 = next1;
        temp2 = next2;
    }
}

// Driver code
int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Creating the first linked list
    appendNode(&list1, 1);
    appendNode(&list1, 2);
    appendNode(&list1, 3);
    printf("List 1: ");
    printList(list1);

    // Creating the second linked list
    appendNode(&list2, 10);
    appendNode(&list2, 20);
    appendNode(&list2, 30);
    appendNode(&list2, 40); // Extra node in list2
    printf("List 2: ");
    printList(list2);

    // Merging alternate nodes of both lists
    mergeAlternate(list1, list2);

    printf("Merged List: ");
    printList(list1);

    printf("Remaining List 2: ");
    printList(list2);

    return 0;
}

