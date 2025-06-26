#include <stdio.h>
#include <stdlib.h>

// binary search

void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n -1; i++) {
        for (int j = 0; j < n -1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int target) {
    int start = 0, end = n - 1;
    int mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int main() {
    int n, target;
    printf("Enter number of elements in array:");
    scanf("%d", &n);

    if (n<=0) {
        printf("Invalid Input");
        return 0;
    }

    int *arr = (int *) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter target number:");
    scanf("%d", &target);

    sort(arr, n);

    int result = binarySearch(arr,n,target);
    if (result == -1) {
        printf("Element not found");
    }
    else {
        printf("Element found in: %d", result);
    }
    return 0;
}




