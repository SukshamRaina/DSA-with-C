/*
Problem Statement

Given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Input Format

Input string i.e s

Constraints

1 <= s.length <= 100000
s consists of lowercase English letters.
Output Format

Print the final string after all such duplicate removals have been made.

Sample Input 0

abbaca
Sample Output 0

ca
Explanation 0

Input: s = "abbaca" Output: "ca" Explanation: For example, in "abbaca" we could remove "bb" 
since the letters are adjacent and equal, and this is the only possible move. The result of 
this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100000  
int top=-1;
char stack[MAX];

void remove_Duplicates(char *s){
    int size = strlen(s);
    for(int i=0;i<size;i++){
        if(top==-1){
            stack[++top]=s[i];
        }
        else{
            if(stack[top]==s[i]){
                top--;
            }
            else{
                stack[++top]=s[i];
            }
        }
    }
}

int main(){

char s[MAX];
printf("Enter the string : ");
scanf("%s",s);
removeduplicates(s);
    
    return 0;
}
