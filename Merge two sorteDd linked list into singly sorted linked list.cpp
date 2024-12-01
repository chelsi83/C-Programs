#include <stdio.h>
#include <stdlib.h>

// Node structure for the singly linked list
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

// Function to append a node to the linked list
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

// Function to merge two sorted linked lists into one sorted linked list
Node* mergeSortedLists(Node* list1, Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    Node* mergedHead = NULL;

    if (list1->data < list2->data) {
        mergedHead = list1;
        list1 = list1->next;
    } else {
        mergedHead = list2;
        list2 = list2->next;
    }

    Node* current = mergedHead;

    while (list1 && list2) {
        if (list1->data < list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // Append the remaining nodes
    if (list1) {
        current->next = list1;
    } else if (list2) {
        current->next = list2;
    }

    return mergedHead;
}

// Function to print a linked list
void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeLinkedList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function for testing
int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Create first sorted linked list: 1 -> 3 -> 5
    appendNode(&list1, 1);
    appendNode(&list1, 3);
    appendNode(&list1, 5);

    // Create second sorted linked list: 2 -> 4 -> 6
    appendNode(&list2, 2);
    appendNode(&list2, 4);
    appendNode(&list2, 6);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Merge the two lists
    Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    // Free the merged list
    freeLinkedList(mergedList);

    return 0;
}

