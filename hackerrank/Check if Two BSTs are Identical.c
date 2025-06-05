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
int areidentical(node* root1,node* root2){
        if(root1==NULL && root2 == NULL) return 1;
        if(root1==NULL || root2 == NULL) return 0;
        return (root1->data == root2->data)&& areidentical(root1->left,root2->left)&&areidentical(root1->right,root2->right);
}
int main() {
        node* root1=NULL;
        node* root2=NULL;
        int n,value;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
                scanf("%d",&value);
                root1=insert(root1,value);

}
         for(int i=0;i<n;i++){
                scanf("%d",&value);
                root2=insert(root2,value);

}
if (areidentical(root1, root2))
        printf("Identical\n");
    else
        printf("Not Identical\n");
    
}
