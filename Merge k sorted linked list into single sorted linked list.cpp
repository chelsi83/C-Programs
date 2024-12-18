#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Function to merge two sorted linked lists
Node* mergeTwoLists(Node* l1, Node* l2) {
    Node dummy;
    dummy.next = NULL;
    Node* tail = &dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;

    return dummy.next;
}

// Function to merge k sorted linked lists
Node* mergeKLists(Node** lists, int k) {
    if (k == 0) return NULL;
    if (k == 1) return lists[0];

    while (k > 1) {
        int i = 0, j = 0;
        for (i = 0, j = 0; i < k - 1; i += 2, j++) {
            lists[j] = mergeTwoLists(lists[i], lists[i + 1]);
        }
        if (i < k) {
            lists[j] = lists[i];
            j++;
        }
        k = j;
    }
    return lists[0];
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
    int k = 3; // Number of linked lists
    Node* lists[k];

    // Initialize linked lists
    lists[0] = NULL;
    appendNode(&lists[0], 1);
    appendNode(&lists[0], 4);
    appendNode(&lists[0], 5);

    lists[1] = NULL;
    appendNode(&lists[1], 1);
    appendNode(&lists[1], 3);
    appendNode(&lists[1], 4);

    lists[2] = NULL;
    appendNode(&lists[2], 2);
    appendNode(&lists[2], 6);

    // Print the original linked lists
    printf("Original lists:\n");
    for (int i = 0; i < k; i++) {
        printf("List %d: ", i + 1);
        printList(lists[i]);
    }

    // Merge the k sorted linked lists
    Node* mergedList = mergeKLists(lists, k);

    // Print the merged linked list
    printf("\nMerged sorted list:\n");
    printList(mergedList);

    return 0;
}

