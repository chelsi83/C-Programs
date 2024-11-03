#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node 
{
    int data;           // Data part of the node
    struct Node* next;  // Pointer to the next node
};

// Function to create a new node and return its pointer
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for the new node
    newNode->data = data;      // Set the data
    newNode->next = NULL;      // Initialize next as NULL
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data)
 {
    struct Node* newNode = createNode(data);  // Create a new node with given data
    if (*head == NULL) {          // If the list is empty, make newNode the head
        *head = newNode;
    } 
    else
     {
        struct Node* temp = *head; // Temporary pointer to traverse the list
        while (temp->next != NULL) {
            temp = temp->next;     // Move to the last node
        }
        temp->next = newNode;      // Link last node to newNode
    }
}

// Function to display all nodes in the list
void displayList(struct Node* head) 
{
    struct Node* temp = head;      // Temporary pointer to traverse the list
    printf("Linked List: ");
    while (temp != NULL) 
    {         // Traverse until the end of the list
        printf("%d -> ", temp->data);  // Print the data of each node
        temp = temp->next;             // Move to the next node
    }
    printf("NULL\n");               // End of the list
}

int main() 
{
    struct Node* head = NULL;       // Initialize an empty list
    int n, data;

    printf("Enter the number of nodes");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);   // Insert each new node at the end
    }

    displayList(head);              // Display the final list

    return 0;
}

