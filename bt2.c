#include <stdio.h>
#include <stdlib.h>

// Tìm  và in ra chỉ số của phần tử lớn nhất đầu tiên trong mảng

int main() {
    int n;
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

    int max = arr[0];
    int indexMax =0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max =arr[i];
            indexMax = i;
        }
    }

    printf("The maximum element is %d", max);
    printf("The maximum element's index is %d", indexMax);

    free(arr);
}




