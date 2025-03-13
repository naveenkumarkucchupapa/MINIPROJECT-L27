#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function prototypes
struct TreeNode* insertLevelOrder(struct TreeNode* root, int arr[], int i, int n);
void preOrder(struct TreeNode* root);
void inOrder(struct TreeNode* root);
void postOrder(struct TreeNode* root);
void levelOrder(struct TreeNode* root);
struct TreeNode* search(struct TreeNode* root, int value);
int height(struct TreeNode* root);
struct TreeNode* deleteNode(struct TreeNode* root, int key);
struct TreeNode* minValueNode(struct TreeNode* node);
void printTree(struct TreeNode* root);

int main() {
    char input[1024];
    int choice, value, n, i = 0;

    printf("Enter the elements of the binary tree in level order (space-separated, use 'null' for empty nodes):\n");
    fgets(input, sizeof(input), stdin);
    
    // Parse the input string into an array of integers
    char* token = strtok(input, " ");
    int arr[100];
    n = 0;
    while (token != NULL) {
        if (strcmp(token, "null") == 0) {
            arr[n++] = -1;  // Use -1 to represent null nodes
        } else {
            arr[n++] = atoi(token);
        }
        token = strtok(NULL, " ");
    }

    struct TreeNode* root = NULL;
    root = insertLevelOrder(root, arr, 0, n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Pre-order Traversal\n");
        printf("2. In-order Traversal\n");
        printf("3. Post-order Traversal\n");
        printf("4. Level-order Traversal\n");
        printf("5. Search for a value\n");
        printf("6. Find height of tree\n");
        printf("7. Delete a node\n");
        printf("8. Print Tree\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Pre-order Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 2:
                printf("In-order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Post-order Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Level-order Traversal: ");
                levelOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct TreeNode* result = search(root, value);
                if (result != NULL) {
                    printf("Found node with value: %d\n", value);
                } else {
                    printf("Node with value %d not found.\n", value);
                }
                break;
            case 6:
                printf("Height of tree: %d\n", height(root));
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 8:
                printf("Tree Structure:\n");
                printTree(root);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to insert nodes in level order
struct TreeNode* insertLevelOrder(struct TreeNode* root, int arr[], int i, int n) {
    if (i < n) {
        if (arr[i] == -1) {
            return NULL;
        }
        struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp->data = arr[i];
        temp->left = insertLevelOrder(root, arr, 2 * i + 1, n);
        temp->right = insertLevelOrder(root, arr, 2 * i + 2, n);
        root = temp;
    }
    return root;
}

// Pre-order traversal (Root -> Left -> Right)
void preOrder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// In-order traversal (Left -> Root -> Right)
void inOrder(struct TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Post-order traversal (Left -> Right -> Root)
void postOrder(struct TreeNode* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// Level-order traversal (Breadth-First Search)
void levelOrder(struct TreeNode* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    int isFirstNode = 1;

    queue[rear++] = root;
    while (front < rear) {
        struct TreeNode* node = queue[front++];
        if (node != NULL) {
            if (!isFirstNode) {
                printf(" ");
            }
            printf("%d", node->data);
            isFirstNode = 0;
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        }
    }
    printf("\n");
}

// Function to search a value in the binary tree
struct TreeNode* search(struct TreeNode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    struct TreeNode* leftResult = search(root->left, value);
    if (leftResult != NULL) {
        return leftResult;
    }
    return search(root->right, value);
}

// Function to find the height of the binary tree
int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to delete a node in the binary tree
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found
        printf("Deleting node with value: %d\n", root->data);  // Print the deleted value
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to find the minimum value node in the tree
struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to print the tree structure (Level order)
void printTree(struct TreeNode* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    printf("Level order traversal:\n");
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    int isFirstNode = 1;

    queue[rear++] = root;
    while (front < rear) {
        struct TreeNode* node = queue[front++];
        if (node != NULL) {
            if (!isFirstNode) {
                printf(" ");
            }
            printf("%d", node->data);
            isFirstNode = 0;
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        }
    }
    printf("\n");
}
