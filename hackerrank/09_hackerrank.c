/*Write a program to create a stack with N elements and print stack element in desending order.

Input Format

First Line take an input on N
Input N element in stack
Constraints

1 <= N <= 100

Output Format

Display All Stack Element in desending order with space seperated.

Sample Input 0

5
7 1 9 3 8
Sample Output 0

9 8 7 3 1
*/
 

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
        scanf("%d",&n);
        int stack[n];
        for (int i=0;i<n;i++){
                scanf("%d",&stack[i]);
                }
        for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
                if(stack[j]>stack[j+1]){
                int temp=stack[j];stack[j]=stack[j+1];stack[j+1]=temp;
                }
        }
        }
        for (int i=n-1;i>=0;i--)
                printf("%d ",stack[i]);
    return 0;
}