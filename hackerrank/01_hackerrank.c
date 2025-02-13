/*
Write a program to store N elements into the list(Array) and display them.

Input Format

Read list size i.e N
Read N elements into the list
Constraints

No

Output Format

Display all elements of the list in single line with space separated.

Sample Input 0

6
19 23 56 17 78 123
Sample Output 0

19 23 56 17 78 123
*/
#include <stdio.h>
#include<stdlib.h>
void printlist(int*arr,int n){
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}
int main(){
system("cls");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    return 0;
}