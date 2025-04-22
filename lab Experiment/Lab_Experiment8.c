#include <stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node* head = NULL;
struct Node* CreateNode(int ele){
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data=ele;
        temp->prev=temp->next=NULL;
        return temp;
    }
    void insertAtBeg(int ele){
        struct Node* newNode = CreateNode(ele);
        if (head==NULL){
            head=newNode;
        }
        else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        printf("Node added !!!\n");
    }}
    void insertAtEnd(int ele){
        struct Node* newNode = CreateNode(ele);
        if(head==NULL){
            head=newNode;
        }
        else{
            struct Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->prev=temp;
            
        }

        printf("Node added !!!\n");

    }
    void insertAtpos(int ele,int pos){
        if(head==NULL){
            printf("List is empty\n");
        }
        else if(pos==1){
            insertAtBeg(ele);
        }
        else{
            struct Node* newNode = CreateNode(ele);
            struct Node *temp=head;
            int i =1;
            while(i<pos && temp!=NULL){
                temp=temp->next;
                i++;}
            if(temp !=NULL && i>0){
                newNode->prev=temp->prev; 
                temp->prev->next=newNode;
                newNode->next=temp;
                temp->prev=newNode;
                printf("Node added !!!\n");
               
            }
            else 
            printf ("Invalid position!!!\n");
    }
}
void display(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        struct Node *temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }}
    }
void deleteFrombeg(){
    if(head==NULL)
        printf("List is empty\n");
        else{
            struct Node *temp = head;
            head=head->next;
            if(head!=NULL)
                head->prev=NULL;
            free(temp);
            printf("Node deleted !!!\n");
        }
}
void deleteFromEnd(){
    if(head==NULL)
        printf("List is empty!!!\n");
        else{
            struct Node *temp = head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            if(temp->prev!=NULL){
                temp->prev->next=NULL;
            }
            else{
                head=NULL;
            }
            free(temp);
            printf("Node deleted !!!\n");
        }
}
void deleteFromanypos(int pos){
    if(head==NULL)
        printf("List is empty\n");
        else if(pos==1)
            deleteFrombeg();
        else{
            int i=1;
            struct Node *temp = head;
            while(i<pos && temp!=NULL){
                temp=temp->next;
                i++;
            }
            if(temp!=NULL && i>0){
                temp->prev->next=temp->next;
                if(temp->next!=NULL)
                    temp->next->prev=temp->prev;
                free(temp);
                printf("Node deleted !!!\n");
            }
            else
                printf("Invalid position !!!\n");  

        }
}
void search(int ele){
    struct Node *temp = head;
    int pos = 1;
    while(temp != NULL){
        if(temp->data == ele){
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found in the list.\n");
}

int main(){
system("cls");  
int value, pos;
    while(1){
        printf("---------Doubly Linked List---------\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Searching in List\n8. Display\n9. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            printf("Enter value to insert: ");
            scanf("%d",&value);
            insertAtBeg(value);
            break;
            case 2:
            printf("Enter value to insert: ");
            scanf("%d",&value);
            insertAtEnd(value);
            break;
            case 3:
            printf("Enter value to insert: ");
            scanf("%d",&value);
            printf("Enter position to insert: ");
            scanf("%d",&pos);
            insertAtpos(value,pos);
            break;
            case 4:
            deleteFrombeg();
            break;
            case 5:
            deleteFromEnd();
            break;
            case 6:
            printf("Enter position to insert: ");
            scanf("%d",&pos);
            deleteAtanypos(pos);
            break;
            case 7:
            printf("Enter value to search: ");
            scanf("%d",&value);
            search(value);
            break;
            case 8:
            display();
            break;
            case 9:
            exit(0);
            break;
            default:
            printf("Invalid choice\n");
            break;
        }
        printf("\n");
    }
    return 0;
}
