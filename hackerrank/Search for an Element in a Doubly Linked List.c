#include <stdio.h>

int main() {
    int n, x;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &x);

    // Search for x
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}
