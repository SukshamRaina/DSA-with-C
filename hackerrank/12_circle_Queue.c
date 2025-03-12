//circular queue 
#include <stdio.h>
#include<stdlib.h>
#define SIZE 100
int queue[SIZE],front=-1,rear=-1;
int isEmpty(){
    return (front==-1)?1:0;
}
int isFull(){ 
    return((rear+1)%SIZE==front)?1:0;
}

void enqueue(int data){
rear=(rear+1)%SIZE;
queue[rear]=data;
if(front==-1)
    front=rear;
    printf("Data inserted successfully\n");
}

int dequeue(){
    int data = queue[front];
    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%SIZE;
        return data;
}
    

int peek(){ // also known as front
    return queue[front];
}
void display(){
    printf("Queue elements are: \n");
    int i;
    for(i=front;i!=rear;i=(i+1)%SIZE)
    {
        printf("%d ",queue[i]);
    }
    printf("%d ",queue[i]);
}
int main(){
system("cls");
int data;
    while (1){
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            if(isFull())
            {
                printf("Queue overflow !!!\n");
            }
            else
            {
                printf("Enter data: ");
                scanf("%d",&data);
                enqueue(data);
            }
            break;
            case 2:
            if(isEmpty())
            {
                printf("Queue underflow !!!\n");
            }
            else
            {
                printf("%d dequeued from the queue \n",dequeue());
            }
            break;
            case 3:
            if(isEmpty())
            {
                printf("Queue underflow !!!\n");
            }
            else
            {
                printf("Element available in front is %d \n",peek());
            }
            break;
            case 4:
            display();
            printf("\n");
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Invalid choice\n"); 
            break;
    }
}
    return 0;
}
