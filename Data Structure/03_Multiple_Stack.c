//Multiple Stack using array
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100
int stack[MAX], top1 = -1, top2 = MAX;
int isEmpty1(){                             // Function to check if stack 1 is empty
    return (top1 == -1) ? 1 : 0;
}
int isEmpty2(){                             // Function to check if stack 2 is empty
    return (top2 == MAX) ? 1 : 0;
}
int isFull1(){                              // Function to check if stack 1 is full
    return (top1 == top2 - 1) ? 1 : 0;
}
int isFull2(){                              // Function to check if stack 2 is full
    return (top2 == top1 + 1) ? 1 : 0;
}
void push_stack1(int data){
    if(isFull1())
    printf("Stack-1 Overflow !!!\n");
    else{
        stack[++top1]=data;
        printf("Element added \n");
    }
}
void push_stack2(int data){
    if(isFull2())
    printf("Stack-2 Overflow !!!\n");
    else{
        stack[--top2]=data;
        printf("Element added \n");
    }
}
void pop_stack1(){
	if(isEmpty1()){
		printf("Stack-1 Underflow!!!\n");
		return;
	}
	else{
		int val = stack[top1--];
		printf("%d Element is Popped",val);
	}}
void pop_stack2(){
    if(isEmpty2()){
        printf("Stack-2 Underflow!!!\n");
        return ;
        }
        else{
            int val = stack[top2--];
            printf("%d Element is Popped",val);
        }}
void peek_stack1(){
    if(isEmpty1()){
        printf("Stack 1 is empty");
    }
    else{
        printf(stack[top1]);
    }
}
void peek_stack2(){
    if(isEmpty2()){
        printf("Stack 2 is empty");
    }
    else{
        printf(stack[top2]);
    }
}
void show_stack1(){
    if (isEmpty1()){
        printf("Stack 1 is empty");
    }
    else
    {
        int i;
        printf("Stack1 elements are : \n");
        for(i=top1;i>=0;i--)
        printf("%d\n",stack[i]);
    }
    
}
void show_stack2(){
    if (isEmpty2()){
        printf("Stack 2 is empty");
    }
    else
    {
        
        printf("Stack2 elements are : \n");
        for(int i=top2;i<MAX;i++)
        printf("%d\n",stack[i]);
    }
}
int main(){
    system("cls");
    int data;
	while(1){
		printf("1. Push Stack1\n2. Pop Stack1\n3. Peek Stack1\n4. Show Stack1\n5. Push Stack2\n6. Pop Stack2\n7. Peek Stack2\n8. Show Stack2\n9.Exit\n");
	
		int choice, val;
		printf("Enter choice : ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
            printf("Enter data : ");
            scanf("%d",&data);
				push_stack1(data);
				break;
			case 2:
				pop_stack1();
				
				break;
			case 3:
				peek_stack1();
				break;
			case 4:
				show_stack1();
				break;
			case 5:
            printf("Enter data : ");
            scanf("%d",&data);
				push_stack2(data);
				break;
                case 6:
                pop_stack2();break;
                case 7:
                peek_stack2();break;
                case 8:
                show_stack2();break;
			default:
				printf("Invalid choice !!!!!\n");	
		}
		printf("\n\n");
		system("pause");
	}
	return 0;
}