#include <stdio.h>
#include<stdlib.h>
#define SIZE 100
int queue[SIZE],front=-1,rear=-1;
typedef struct PriorityQueue
{
    int element;
    int priority;
} PQ;
PQ pq[SIZE];

int isEmpty(){
    return (front==-1)?1:0;
}
int isFull(){
    return (rear==SIZE-1)?1:0;
}

void enqueue(int data,int priority){
    
    rear++;
    pq[rear].element=data;
    pq[rear].priority=priority;
    if(front==-1)
        front=rear; 
    printf("Data inserted successfully\n");
}
int getHighestPriority()
{
    int max=0,index=-1;
    for (int i = front; i <= rear; i++)
    {
        if(pq[i].priority>max){
       max=pq[i].priority;
       index=i;
    }
}
    return index;
    
}
    
int dequeue()
{
  int index = getHighestPriority();
  int data = pq[index].element;
  if(index==front && index==rear)
  front = rear = -1;
  else if(index==front)
  front++;  
  else{
     for(int i = index;i<rear;i++){
    pq[i]=pq[i+1];
  }
  rear--;
  }
  return data;
}
    
int peek(){
    int i = getHighestPriority();
   return pq[i].element;
}
void display(){
    printf("Element available in front is %d \n");
    for(int i = front;i<=rear;i++)
    {
        printf("Element : %d => Priority : %d\n",pq[i].element,pq[i].priority);
    }
}
int main(){
system("cls");
int data,priority;
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
                printf("Enter Data: ");
                scanf("%d",&data);
                printf("Enter Priority: ");
                scanf("%d",&priority);
                enqueue(data,priority);
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
                printf("Element having higher priority is %d \n",peek());
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