#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in a binary tree (level order)
TreeNode* insertNode(TreeNode* root, int data) {
    TreeNode* newNode = createNode(data);
    if (root == NULL) {
        return newNode;
    }

    // Level-order insertion using a queue
    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        TreeNode* temp = queue[front++];

        // Check left child
        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        } else {
            queue[rear++] = temp->left;
        }

        // Check right child
        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        } else {
            queue[rear++] = temp->right;
        }
    }
    return root;
}

// Function for inorder traversal
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function for preorder traversal
void preorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function for postorder traversal
void postorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Main function to test the binary tree implementation
int main() {
    TreeNode* root = NULL;

    // Insert nodes into the binary tree
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 6);
    root = insertNode(root, 7);

    printf("Inorder Traversal:\n");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal:\n");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal:\n");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

