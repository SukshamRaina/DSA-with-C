#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct node{
        struct node* left;
        int data;
        struct node* right;
} node;
node* create(int value){
        node * newnode=(node*)malloc(sizeof(node));
        newnode->data=value;
        newnode->left=newnode->right=NULL;
        return newnode;
}
node* insert(node* root,int value){
        if (root==NULL) 
                return create(value);
        else if(value<root->data)
                root->left=insert(root->left,value);
        else
                root->right=insert(root->right,value);
        return root;
}
int sumofnodes(node* root){
    if (root==NULL) return 0;
        return root->data+sumofnodes(root->left)+sumofnodes(root->right);
}
int main() {
        node* root=NULL;
        int n,value;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
                scanf("%d",&value);
                root=insert(root,value);

}
int sum = sumofnodes(root);
        printf("%d",sum);
        return 0;
    
}
