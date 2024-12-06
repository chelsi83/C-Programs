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

// Function to find a pair with a given sum in the linked list
void findPairWithSum(struct Node* head, int target) {
    // Hash table to store visited elements
    int hash[10000] = {0}; // Assuming the values are within the range 0-9999

    struct Node* current = head;
    int found = 0;

    while (current != NULL) {
        int complement = target - current->data;

        // Check if complement is already in the hash table
        if (complement >= 0 && hash[complement]) {
            printf("Pair found: (%d, %d)\n", complement, current->data);
            found = 1;
        }

        // Add current node's value to the hash table
        hash[current->data] = 1;
        current = current->next;
    }

    if (!found) {
        printf("No pair with the given sum found.\n");
    }
}

// Main function
int main() {
    // Creating the linked list
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(15);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(30);

    printf("Linked List: ");
    printList(head);

    int target;
    printf("Enter the target sum: ");
    scanf("%d", &target);

    // Find and print pairs with the given sum
    findPairWithSum(head, target);

    return 0;
}

