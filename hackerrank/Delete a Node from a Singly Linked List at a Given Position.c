#include <stdio.h>

int main() {
    int n, pos;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position\n");
        return 0;
    }

    // Shift elements to delete the one at position `pos`
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print the updated array (now of size n - 1)
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
