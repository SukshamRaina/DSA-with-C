#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertBST(Node* root, int val) {
    if (val == -1) return root;
    if (root == NULL) return createNode(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

int findMinBST(Node* root) {
    if (!root) return -1;
    while (root->left)
        root = root->left;
    return root->data;
}

int main() {
    int n;
    scanf("%d", &n);

    int val;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insertBST(root, val);  // -1s are skipped
    }

    printf("%d\n", findMinBST(root));
    return 0;
}
