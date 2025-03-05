#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int precedence(char opr){
    switch(opr){
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
        default:
        return -1;
    }
}

char* convert_Infix_To_Postfix(char* exp){
    int size = strlen(exp),top = -1,index=0;
    char* str = (char*)malloc(size+1); //output string
    char stack[size];           //operator stack
    for(int i = 0;i<size;i++){  
        char ch=exp[i];
        if(isalnum(ch)){
            str[index++]=ch;
        }

        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            char opr = stack[top];
            while(top!=-1 && precedence(ch)<=precedence(stack[top])){
                str[index++]=stack[top--];
            }
            stack[++top]=ch;

        }
        else if (ch == '('){
            stack[index++]=ch;

        }
        else if (ch == ')'){
            while(stack[top]!='('){
                str[index++]=stack[top--];
            }
            top--;
        }
    }
    while(top!=-1){
        str[index++]=stack[top--];
    }
    str[index]='\0';
    return str;
}


int main(){
    system("cls");
    int str[100];
    printf("Enter the infix expression: ");
    gets(str);
    printf("The postfix expression is: %s",convert_Infix_To_Postfix(str));
    return 0;
}