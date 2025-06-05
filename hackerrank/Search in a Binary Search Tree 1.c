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
int search(TreeNode* root,int target){
        if (root==NULL)return 0;
        if (root->data==target)return 1;
        else if (root->data<target)return search(root->right,target);
        else return search(root->left,target);

}



int main() {
        TreeNode* root= NULL;
        int n,value;
        scanf("%d",&n);
        for (int i=0;i<n;i++){
                scanf("%d",&value);
  root=insert(root,value);
        }
        int target;
        scanf("%d",&target);
        
        if(search(root,target))
                printf("Found");
        else 
                printf("Not Found");
    return 0;
}
