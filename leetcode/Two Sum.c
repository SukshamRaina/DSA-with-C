/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* arr, int n, int target, int* returnSize) {
    int i,j;
    int* result = malloc(sizeof(int) * 2);
    for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if(arr[i]+arr[j]==target){
           
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
        }
    }}
    free(result);
    *returnSize = 0;
    return NULL;
}
