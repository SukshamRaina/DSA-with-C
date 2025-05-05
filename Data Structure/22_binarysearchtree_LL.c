#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    struct TreeNode *left;
    int data;
    struct TreeNode *right;
} TreeNode;

TreeNode* createnode(int data) {
    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return createnode(value);
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

TreeNode* search(TreeNode* root, int value) {
    if (root == NULL || root->data == value)
        return root;
    else if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

TreeNode* findmin(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

TreeNode* delete(TreeNode* root, int value) {
    if (root == NULL) {
        return NULL;
    } else if (value < root->data)
        root->left = delete(root->left, value);
    else if (value > root->data)
        root->right = delete(root->right, value);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        } else if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else {
            TreeNode* temp = findmin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

// // Level Order Traversal using queue
// void levelorder(TreeNode* root) {
//     if (root == NULL) return;
//     TreeNode* queue[100];
//     int front = 0, rear = 0;
//     queue[rear++] = root;

//     while (front < rear) {
//         TreeNode* current = queue[front++];
//         printf("%d ", current->data);
//         if (current->left != NULL) queue[rear++] = current->left;
//         if (current->right != NULL) queue[rear++] = current->right;
//     }
// }

int main() {
    int choice, value;
    TreeNode* root = NULL;
    TreeNode* found = NULL;
    printf("Binary Search Tree Operations:\n");
    printf("1. Insert\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Search\n6. Delete\n7. Exit\n");
    while (1) {
        
        printf("Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            // case 5:
            //     printf("Level Order: ");
            //     levelorder(root);
            //     printf("\n");
            //     break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                found = search(root, value);
                if (found)
                    printf("Found: %d\n", found->data);
                else
                    printf("Not Found.\n");
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = delete(root, value);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
