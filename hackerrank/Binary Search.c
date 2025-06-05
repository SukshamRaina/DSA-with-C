#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,target;
        
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&target);
        
        int start=0,end=n-1;
        
        while(start<=end){
                int mid=(start+end)/2;
                if(arr[mid]==target)
                        break;
                else if(arr[mid]<target)
                        start=mid+1;
                else 
                        end=mid-1;
        }
    if (start<=end)
            printf("Found");
else 
        printf("Not Found");
return 0;
}
