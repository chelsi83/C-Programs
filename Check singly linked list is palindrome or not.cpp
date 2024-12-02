#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check if the linked list is a palindrome
bool isPalindrome(struct Node* head) {
    if (!head || !head->next) return true; // Empty or single-node list

    // Find the middle of the linked list
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    struct Node* secondHalf = reverseList(slow);
    struct Node* firstHalf = head;

    // Compare the two halves
    struct Node* temp = secondHalf;
    bool isPalin = true;
    while (temp) {
        if (firstHalf->data != temp->data) {
            isPalin = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    // Restore the original list (optional)
    reverseList(secondHalf);

    return isPalin;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test the program
int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(1);

    printf("Original list: ");
    printList(head);

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}

