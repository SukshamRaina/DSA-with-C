//experiment no 15 date 30
#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
    struct TreeNode* left;
    int data;
    struct TreeNode* right;
}Node;
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left=newNode->right=NULL;
    return newNode;
}
Node* insert(Node* root,int value){
    if(root==NULL)
        return createNode(value);
        else {
Node* queue[100];
    int front =0 , rear = 0;
    queue[rear++]=root;
    while(front!=rear){
        Node* temp = queue[front++];
        if(temp->left == NULL){
        temp->left = createNode(value);
        break;
        }
        else if(temp->right==NULL){
        temp->right = createNode(value);
        break;
        }
        else{
            queue[rear++]=temp->left;
            queue[rear++]=temp->right;
        }
    }
    return root;
    }
}
void preorder(Node* root){
    if(root!=NULL){
     printf("%d ",root->data);
     preorder(root->left);
     preorder(root->right);
    }
}
void inorder(Node* root){
     if(root!=NULL){
         inorder(root->left);
         printf("%d ",root->data);
         inorder(root->right);
    }
}
void postorder(Node* root){
 if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
 }
}
// void levelorder(struct TreeNode* root){ // we use only queue for level Order 
//     struct TreeNode* queue[100];
//     int front =0 , rear = 0;
//     queue[rear++]=root;
//     while(front!=rear){
//         struct TreeNode* temp = queue[front++];
//         printf("%d ",temp->data);
//         if(temp->left != NULL)
//         queue[rear++]=temp->left;
//         if(temp->right!=NULL)
//         queue[rear++]=temp->right;
//     }
// }
Node* search(Node* root,int value){
         Node* queue[100];
    int front =0 , rear = 0;
    queue[rear++]=root;
    while(front!=rear){
        Node* temp = queue[front++];
      if(value==temp->data)
      return temp;
        if(temp->left != NULL)
        queue[rear++]=temp->left;
        if(temp->right!=NULL)
        queue[rear++]=temp->right;
    }
    return NULL;
}
Node* findDeepest(Node* root){
     Node* queue[100];
    int front =0 , rear = 0;
    queue[rear++]=root;
    Node* temp;
    while(front!=rear){
        temp = queue[front++];
      if(temp->left!=NULL)
      queue[rear++]=temp->left;
      if(temp->right!=NULL)
      queue[rear++]=temp->right;
    }
    int i = (rear-2)/2;
    if(queue[i]->left==temp)
    queue[i]->left = NULL;
    else
    queue[i]->right = NULL;
    return temp;
}
void delete(Node* root,int value){
        Node* temp = search(root,value);
        if(temp==NULL){
            printf("Element Not found !!!!\n");
        }
        else{
           Node* last = findDeepest(root);
           temp->data = last->data;
           free(last);
           printf("Node Deleted !!!!\n");
        }
}
int main (){
        int choice,value;
        Node* root = NULL;
        printf("Binary Tree Implementation Using Linked List\n");
        printf("1. Insert\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Search\n6. Delete\n7. Exit\n");
        while(1){
            printf("Enter the choice = ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                printf("Enter the value to be inserted : ");
                scanf("%d",&value);
                root = insert(root,value);
                printf("Node Inserted !!!!\n");
                break;
                case 2:
                printf("Preorder Traversal = ");
                preorder(root);
                break;
                case 3:
                printf("Inorder Traversal = ");
                inorder(root);
                break;
                case 4:
                printf("Postorder Traversal = ");
                postorder(root);
                break;
                // case 5:
                // printf("Level Order Traversal = ");
                // levelorder(root);
                // break;
                case 5:
                printf("Enter the value to be searched = ");
                scanf("%d",&value);

                Node* searchNode = search(root,value);
                if(searchNode!=NULL)
                printf("Element Found = %d\n",searchNode->data);
                else
                printf("Element Not Found !!!!\n");
                break;
                case 6:
                printf("Enter the value to be deleted = ");
                scanf("%d",&value);
                delete(root,value);
                break;
                case 7:
                exit(0);
                break;
                default:
                printf("Invalid Choice!!!!!\n");
            }
            printf("\n");
        }
}