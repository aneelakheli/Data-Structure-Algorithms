#include <stdio.h>

void bubble_sort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 10;  // Initialize n to 10
    int a[10], i;
    printf("Enter the data items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("The data items before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    bubble_sort(a, n);
    printf("The data items after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
