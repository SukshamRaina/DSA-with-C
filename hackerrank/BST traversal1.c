#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Node{
    struct Node* left;
    int data;
    struct Node* right;
} Node;

Node* createNode(int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->left=newNode->right=NULL;
    return newNode;
}
Node* insert(Node* root,int value){
if(root==NULL)
    return createNode(value);
else if (value < root->data)
    root->left=insert(root->left,value);
else if (value > root->data)
    root->right=insert(root->right,value);
return root;
}
void preOrder(Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
        
}
void inOrder(Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        
        inOrder(root->right);
    }
        
}
void postOrder(Node* root){
    if(root!=NULL){
        
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
        
}
int main() {
    Node* root = NULL;
    int n,value;
    scanf("%d",&n);
    for(int i =0;i<n;i++){
    scanf("%d",&value);
    root = insert(root,value);
    }
    preOrder(root);
    printf("\n");
    inOrder(root);printf("\n");
    postOrder(root);printf("\n");
   
    return 0;
}
