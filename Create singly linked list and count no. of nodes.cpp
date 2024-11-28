#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a singly linked list
struct Node* createList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* tail = NULL;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int data;
        printf("Element %d: ", i + 1);
        scanf("%d", &data);

        temp = createNode(data);
        if (head == NULL) {
            head = temp;
        } else {
            tail->next = temp;
        }
        tail = temp;
    }

    return head;
}

// Function to count the number of nodes in the list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to free the allocated memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The list cannot be created with zero or negative nodes.\n");
        return 0;
    }

    struct Node* head = createList(n);

    int count = countNodes(head);
    printf("The number of nodes in the list: %d\n", count);

    freeList(head);

    return 0;
}

