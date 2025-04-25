//Implement stack using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top = NULL;
//struct node*top=NULL;
void push(int ele){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Stack Overflow\n");
    }
    else{
        temp->data=ele;
        temp->next=top;
        top=temp;
        printf("Node Added!!!\n");
    }
    
}
int pop(){
    if(top==NULL){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        int val=top->data;
        struct node* temp = top;
        top=top->next;
        free(temp);
        printf("Node Deleted!!!\n");
        return val;
    }
}
void peek(){
    if(top==NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("Top element is %d\n",top->data);
    }
}
void display(){
    if(top==NULL){
        printf("Stack is empty\n");
    }
    else{
        struct node* temp=top;
        printf("Elements in the stack are: \n");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
            printf("\n");
        }
        
    }
}
int main(){
    system("cls");
    printf("\n----Stack using Linked List----\n");
    printf("1. Push\n2. Pop\n3. Peek \n4. Display\n5. Exit\n");
    int val;
    while (1){
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%d",&val);
                push(val);
                break;
            case 2:
            val=pop();
            if(val!=-1){
                printf("Element popped is %d\n", val);
            }
            else{
                printf("Stack is empty\n");
                }
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!!!\n");
        }
    }
}