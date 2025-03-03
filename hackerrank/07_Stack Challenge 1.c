/*
Write a program to implement a stack using an array and implement the push and pop function to perform following operations.

Push 3 elements in a stack
Pop 1 element from stack
Push 2 elements in the stack.
Pop 3 elements from the stack.
Display all stack element
Output Format

Display all stack element in single line with space seperated.

Sample Input 0

90 12 56
88 12
Sample Output 0

90
*/
#include <stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX], top = -1;
void push(int value){
    if(top==MAX-1){
       return ;
    }
        else{
                int value;//...
        scanf("%d", &value);
    stack[++top]=value;}
}
int pop(int data)
{
    if(top== -1)
        return 0;
    else
    {
        stack[top--] = data;
        return 1;
    }}
void show(){
    if(top == -1)
        return ;
    
    else{
    int i;
    for (i=top;i>=0;i--)
    printf("%d ",stack[i]);}
}
int main(){
push(90);
push(12);   
push(56);
pop(56);
push(88);
push(12);
pop(12);pop(88);pop(12);
show();
    return 0;
}
