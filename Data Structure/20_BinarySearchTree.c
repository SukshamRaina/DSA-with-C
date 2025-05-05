#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int tree[MAX];

// Initialize the tree with -1
void init() {
    for (int i = 0; i < MAX; i++)
        tree[i] = -1;
}

// Insert a value into the BST
void insert(int val, int root) {
    if (root >= MAX) {
        printf("Insertion failed!!!\n");
        return;
    }
    if (tree[root] == -1)
        tree[root] = val;
    else if (val < tree[root])
        insert(val, 2 * root + 1);
    else if (val > tree[root])
        insert(val, 2 * root + 2);
}

// Preorder traversal: ROOT, LEFT, RIGHT
void preorder(int root) {
    if (root >= MAX || tree[root] == -1)
        return;
    printf("%d ", tree[root]);
    preorder(2 * root + 1);
    preorder(2 * root + 2);
}

// Inorder traversal: LEFT, ROOT, RIGHT
void inorder(int root) {
    if (root >= MAX || tree[root] == -1)
        return;
    inorder(2 * root + 1);
    printf("%d ", tree[root]);
    inorder(2 * root + 2);
}

// Postorder traversal: LEFT, RIGHT, ROOT
void postorder(int root) {
    if (root >= MAX || tree[root] == -1)
        return;
    postorder(2 * root + 1);
    postorder(2 * root + 2);
    printf("%d ", tree[root]);
}

// Search for a value and return its index
int search(int target, int i) {
    if (i >= MAX || tree[i] == -1)
        return -1;
    else if (tree[i] == target)
        return i;
    else if (target < tree[i])
        return search(target, 2 * i + 1);
    else
        return search(target, 2 * i + 2);
}

// Find index of minimum value starting from index i
int FindMin(int i) {
    while (i < MAX && tree[2 * i + 1] != -1)
        i = 2 * i + 1;
    return i;
}

// Find index of maximum value starting from index i
int FindMax(int i) {
    while (i < MAX && tree[2 * i + 2] != -1)
        i = 2 * i + 2;
    return i;
}

// Delete a value from the BST
void delete(int value, int i) {
    i = search(value, i);
    if (i == -1) {
        printf("Element not found\n");
        return;
    }

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Case 1: No children
    if ((left >= MAX || tree[left] == -1) && (right >= MAX || tree[right] == -1)) {
        tree[i] = -1;
    }
    // Case 2: Only left child
    else if (right >= MAX || tree[right] == -1) {
        int max = FindMax(left);
        tree[i] = tree[max];
        delete(tree[max], max);
    }
    // Case 3: Right child exists (one or two children)
    else {
        int min = FindMin(right);
        tree[i] = tree[min];
        delete(tree[min], min);
    }
}

int main() {
    system("cls"); 
    init();

    int choice, value;

    printf("==== Binary Search Tree====\n");
    printf("1. Insert\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Search\n6. Delete\n7. Exit\n");
    while (1) {       
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value, 0);
                break;

            case 2:
                printf("Preorder Traversal: ");
                preorder(0);
                printf("\n");
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(0);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(0);
                printf("\n");
                break;

            case 5:
                printf("Enter element to search: ");
                scanf("%d", &value);
                int index;
                index = search(value, 0);
                if (index == -1)
                    printf("Element not found\n");
                else
                    printf("Element found at index %d\n", index);
                break;

            case 6:
                printf("Enter element to delete: ");
                scanf("%d", &value);
                delete(value, 0);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
