/*Write a program to create a list using array and search the given value in the list.

Input Format

Read List Size i.e. N
Read N elements in list
Read searching element
Constraints

1 <= N <= 1000 Strong Text

Output Format

Display message Found if element is avaiable in the list otherwise display message Not Found.

Sample Input 0

5
89 23 18 34 78
34
Sample Output 0

Found*/
#include <stdio.h>

void search(int*arr,int n){
    int value;
    scanf("%d",&value);
    for(int i=0;i<n;i++){
        if(arr[i]==value){
            printf("Found");
        
            
        }
        else
        {
            printf("Not Found");
        }
    }
}
int main(){
    int n;
    scanf ("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    search(arr,n);
    return 0;
}
