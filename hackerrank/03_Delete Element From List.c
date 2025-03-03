/*
Write a program to create a list using array and delete the first occurrence of specified element from the list and print.

Input Format

Read list size i.e N
Read N elements in list
Read element that you want to delete
Constraints

1 <= N <= 100

Output Format

Display the list with space seperated after deleteing the specified element.

Sample Input 0

6
90 12 45 11 67 120
11
Sample Output 0

90 12 45 67 120
*/
#include <stdio.h>
void delete(int*arr,int*size){
    int value,i,j;
    scanf("%d",&value);
    for(i=0;i<*size;i++){
        if(arr[i]==value){
            for (j=i;j<*size;j++){
                arr[j]=arr[j+1];
            }
            (*size)--;
            break;
        }
    }
    
}
void printlist(int*arr,int n){
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i=n;i++)
        scanf("%d",&arr[i]);
    delete(arr,&n);
    printlist(arr,n);

    return 0;
}
