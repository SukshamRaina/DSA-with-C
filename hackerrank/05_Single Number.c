/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Solve the above question on leetcode also:

https://leetcode.com/problems/single-number/description/

Input Format

Read Array Size i.e N Read N elements in an array

Constraints

1 <= array.length <= 3 * 10000
-3 * 10000 <= array[i] <= 3 * 10000
Each element in the array appears twice except for one element which appears only once.
Output Format

Print the element appears only once.

Sample Input 0

3
2 2 1
Sample Output 0

1
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    scanf("%d", &n);
    int arr[n], freq[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int count = 0;
    for (j = 0; j < n; j++) {
        freq[j] = -1;
    }
    for (i = 0; i < n; i++) {
        count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = 0;
            }
        }
        if (freq[i] != 0) {
            freq[i] = count;
        }
    }
    for (i = 0; i < n; i++) {
        if (freq[i] == 1) {
            printf("%d", arr[i]);
        }
    }
    return 0;
}
