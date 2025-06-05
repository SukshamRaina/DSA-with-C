#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n],flag=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int target;
        scanf("%d",&target);
    for (int i=0;i<n;i++){
            if(arr[i]==target){
                flag=1;
                    break;
}  
    }
    if(!flag)
            printf("Not Found");
        else
                printf("Found");

return 0;
}
