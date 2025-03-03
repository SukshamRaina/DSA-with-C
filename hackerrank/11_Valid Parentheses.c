/*
Problem Statement Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
**Solve this question on leetcode also : **

https://leetcode.com/problems/valid-parentheses/description/?envType=problem-list-v2&envId=stack

Input Format

Take string as a input i.e s
Constraints

1 <= s.length <= 10,000
s consists of parentheses only '()[]{}'.
Output Format

Print True if a given string expression is correctly parenthesized otherwise print False

Sample Input 0

()[]{}
Sample Output 0

True
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int valid(char *str){
int len =strlen(str);
    char stack [len];
    int top =-1 ;
        for (int i=0 ; i<len ;i++){
            char ch=str[i];
            if(ch =='('||ch =='{'||ch =='[')
                stack[++top]=ch;
            else if (ch==')'||ch =='}'||ch==']'){
                if(top ==-1)
                    return 0;
                else if(ch==')'&&stack[top]!='(')
                    return 0;
                else if (ch =='}'&& stack[top]!='{')
                    return 0;
                else if (ch==']'&& stack[top]!='[')
                    return 0;
                else
                    top--;
                }
            }
    if(top==-1)
        return 1;
    else
        return 0;
}
        
int main() {
    char str[100];
    scanf("%s",str);
    int result =valid(str);
    if(result==1)
        printf("True");
    else
        printf("False");

       
    return 0;
}
